#ifndef ODOMETRY_HPP
#define ODOMETRY_HPP

#include "main.h"

#include "setup.hpp"
#include "pid.hpp"

Pid drivePID(1, 0, 0);
Pid turnPID(1, 0, 0);

double xPos = 0, yPos = 0;
double heading = 0;

double dx, dy;

double headingRad = 0;
double horizOdom = 0;
double vertOdom = 0;

double headingRadLast = 0;
double horizOdomLast = 0;
double vertOdomLast = 0;

bool resetPos = false;
double resetX = 0, resetY = 0, resetH = 0;

//alliance's left corner as (0, 0), heading = 0 if looking towards the right wall

void calibrate(){
    xPos = 0, yPos = 0, heading = 0;

    headingRad = 0;
    horizOdom = 0;
    vertOdom = 0;

    headingRadLast = 0;
    horizOdomLast = 0;
    vertOdomLast = 0;

    Imu.reset();

    master.rumble("-");
}

void setPos(double x = xPos, double y = yPos, double h = heading) {
    resetX = x;
    resetY = y;
    resetH = h;

    resetPos = true;
}

void odometryTask() {
	while (true) {
        
        if (resetPos){
            xPos = resetX;
            yPos = resetY;
            heading = resetH;
            Imu.set_heading(heading);

            resetPos = false;
        }

        heading = Imu.get_heading();

        headingRad = heading * DEG_RAD; //heading in radians
        horizOdom = HorizontalRotation.get_position()/36000 * TRACKING_WHEEL_CIRCUMFERENCE;
        vertOdom = VerticalRotation.get_position()/36000 * TRACKING_WHEEL_CIRCUMFERENCE; //in inches

        double dHeadingRad = headingRad - headingRadLast;

        // dHeadingRad = fmod(headingRad - headingRadLast + 2 * M_PI, 2 * M_PI);
        // if (dHeadingRad > M_PI) dHeadingRad -= 2 * M_PI; // (-pi, pi]

        double dHorizOdom = horizOdom - horizOdomLast;
        double dVertOdom = vertOdom - vertOdomLast;

		double localTheta, localX, localY;

        double radius;
        double theta;

		if (fabs(dHeadingRad) < 0.000001) { 
			localX = dHorizOdom;
			localY = dVertOdom;
		} else {
			localX = (2*sin(dHorizOdom/2)) * (dHorizOdom/dHeadingRad - HORIZ_ODOM_OFFSET); 
			localY = (2*sin(dVertOdom/2)) * (dVertOdom/dHeadingRad - VERT_ODOM_OFFSET);
		}

		if (localX < 0.000001 && localY < 0.000001){
			radius = 0;
			localTheta = 0;
		} else {
            radius = hypot(localX, localY); // hypotenuse
			localTheta = atan2(localY, localX); // atan(y/x) but w/ correct quadrants, (-pi, pi]
		}

		theta = localTheta - dHeadingRad/2;

		dx = radius * cos(theta);
		dy = radius * sin(theta);

        xPos += dx;
        yPos += dy;

        headingRadLast = headingRad;
        horizOdomLast = horizOdom;
        vertOdomLast = vertOdom;

        pros::delay(10);
	}
}

bool stop = false;

bool boomerang = true; // move then turn if false
double lead = 0.65;

bool forwards = true;

// boomerang: https://www.desmos.com/calculator/tesrlifjlz

double targetX = 0;
double targetY = 0;
double targetH = 0;

void setTarget(double x, double y, double h = heading) {
    targetX = x;
    targetY = y;
    targetH = h;

    drivePID.resetID();
    turnPID.resetID();
}

double headingError(double targetHeading){
    double headingError = fmod(targetHeading - heading + 360, 360);
    if (headingError > 180) headingError -= 360;
    
    return headingError;
}

void autonDriveTask() {
    while (true) {
    if (!stop){

        double power = 0;
        double turn = 0;

        double distance = hypot(targetX - xPos, targetY - yPos);

        if (boomerang){
            double carrotX = targetX - lead * distance * cos(targetH);
            double carrotY = targetY - lead * distance * sin(targetH);

            if (distance < 10){
                carrotX = targetX;
                carrotY = targetY;
            }

            double headingPos = heading;
            if (!(distance < 0.000001)) headingPos = atan2(carrotY - yPos, carrotX - xPos) / DEG_RAD;
            if (!forwards) headingPos = -headingPos;
            
            if (distance < 10) turnPID.update(headingError(targetH));
            else turnPID.update(headingError(headingPos));

            turn = turnPID.output();

            drivePID.update(hypot(carrotX, carrotY) * sign(cos(headingError(headingPos) * DEG_RAD)));
            power = drivePID.output();

        } else {

            if (distance > 0.1){
                turnPID.update((headingRad - headingRadLast)/DEG_RAD);
                turn = turnPID.output();

                double error = distance;
                if (!forwards) error = -error;
                drivePID.update(error);
                power = drivePID.output();
            } else {
                turnPID.update(headingError(targetH));
                turn = turnPID.output();
                power = 0;
            }
        }

        double leftVelocity = power - turn;
        double rightVelocity = power + turn;

        if (fabs(leftVelocity) > 600 || fabs(rightVelocity) > 600){
            if (fabs(leftVelocity) > fabs(rightVelocity)){

                leftVelocity *= 600/fabs(leftVelocity);
                rightVelocity *= 600/fabs(leftVelocity);
            } else {
                leftVelocity *= 600/fabs(rightVelocity);
                rightVelocity *= 600/fabs(rightVelocity);
            }
        }

        LeftDT.move_voltage(leftVelocity * 20); // max: 600 rpm, 12000 mV
        RightDT.move_voltage(rightVelocity * 20);

    } else {
        LeftDT.move_voltage(0);
        RightDT.move_voltage(0);
    }

    pros::delay(10);
    }
}


void untilTargetPos(double tolerance, double tX = targetX, double tY = targetY, double sec = 999999){
    double start = pros::millis();
    double distance = hypot(tX, tY);

    while (distance > tolerance && (pros::millis() - start) < sec){
        pros::delay(10);
    }
}

void untilStuck(double timeout, double sec = 999999){
    double start = pros::millis();
    double stuck = 0;

    while (stuck < timeout && (pros::millis() - start) < sec){
        if (dx < 0.5 && dy < 0.5) stuck += 10;
        else stuck = 0;
        pros::delay(10);
    }
}

void timeout(double sec){
    pros::delay(sec);
    stop = true;
}

#endif