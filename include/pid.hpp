#ifndef PID_HPP
#define PID_HPP


#include "main.h"
#include "functions.hpp"
#include <math.h>

int sign (double in){
    return (in == 0) ? 0 : fabs(in) / in;
}

double exitMEOW = 0.2;

//float rkP = 5.7, rkI = 0.001, rkD = 45;

void turnPID(double targetDegrees, int sec, int minRPM = 0, int maxRPM = 600){
    double start = pros::millis();
    
    double Kp = 2.26, Ki = 0.00275, Kd = 1.5; 
    double error = static_cast<int>(targetDegrees - ImuSensor.get_heading() + 360) % 360;
    if(error >= 180){
        error -= 360;
    }
    double integral = 0;
    double lastError = error;
    double initialHeading = ImuSensor.get_heading();

    while (fabs(error) > 1.7) {
        error = static_cast<int>(targetDegrees - ImuSensor.get_heading() + 360) % 360;
        if(error >= 180){
            error -=  360;
        }
        integral += error;
        if(error == 0){
            integral = 0;
        }
        if(integral > 300) integral = 300;
        if(integral < -300) integral = -300;

        double out = (error * Kp + integral * Ki + (lastError-error) * Kd);

        if (fabs(out) > maxRPM) out = sign(out) * maxRPM;
        if (fabs(out) < minRPM) out = sign(out) * minRPM;

        if (fabs(out) < exitMEOW) out = 0;

        LeftDT.move_velocity(out);
        RightDT.move_velocity(-out);

        lastError = error;
        if((pros::millis() - start) > sec){
            break;
        }
        pros::delay(10);
    }

    // LeftDT.move_velocity(0);
    // RightDT.move_velocity(0);
    LeftDT.brake();
    RightDT.brake();
}

void movePID(double distance, int sec, int minRPM = 0, int maxRPM = 600){
    double start = pros::millis();
    double Kp = 1.2, Ki = 0.001, Kd = 3.8;
    
    LeftDT.tare_position_all();
    RightDT.tare_position_all();

    int prevError = 0;
    int derivative = 0 ;
    double integral = 0;
    double avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))/3;
    double avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))/3;
    double totalAvgPos = (avgLeftSide + avgRightSide)/2;

    int tVal = dToT(distance)/1.75;

    int error = tVal - totalAvgPos;
    while(fabs(error) > 1.7){
        if((pros::millis() - start) > sec) break;
        integral += error;

        if(error == 0){
            integral = 0;
        }
        if(integral > 300) integral = 300;
        if(integral < -300) integral = -300;

        std::uint32_t now = pros::millis();

        avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))/3;
        avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))/3;
        totalAvgPos = (avgLeftSide + avgRightSide)/2;

        error = tVal - totalAvgPos;
        derivative = error - prevError;
        double out = (error * Kp + derivative * Kd + integral * Ki);

        if (fabs(out) > maxRPM) out = sign(out) * maxRPM;
        if (fabs(out) < minRPM) out = sign(out) * minRPM;
        
        LeftDT.move_voltage(out * 20);
        RightDT.move_voltage(out * 20);

        prevError = error;
        pros::delay(10);
    }

    LeftDT.move_velocity(0);
    RightDT.move_velocity(0);

    // Chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    // double start = pros::millis();
    // // double kP, kI, kD;
    // double kP = 0, kI = 0, kD = 0;
    // double lkP = 0, lkI = 0, lkD = 0;
    
    // LeftDT.tare_position_all();
    // RightDT.tare_position_all();

    // int prevError = 0;
    // int derivative = 0 ;
    // double integral = 0;

    // double avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))/3;
    // double avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))/3;
    // double totalAvgPos = (avgLeftSide + avgRightSide)/2;

    // int tVal = dToT(distance)/1.75;

    // int error = tVal - totalAvgPos;
    // // int errorR = tVal - avgRightSide;

    // while(fabs(error) > 1.7){
    //     if((pros::millis() - start) > sec) break;
    //     integral += error;
    //     // integralR += errorR;

    //     if(error < 0.1){
    //         integral = 0;
    //     }
    //     // if(errorR < 0.1){
    //     //     integralR = 0;
    //     // }
    //     if(integral > 300) integral = 300;
    //     if(integral < -300) integral = -300;

    //     // if(integralR > 300) integralR = 300;
    //     // if(integralR < -300) integralR = -300;

    //     avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))/3;
    //     avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))/3;
    //     double totalAvgPos = (avgLeftSide + avgRightSide)/2;

    //     error = tVal - totalAvgPos;
    //     // errorR = tVal - avgRightSide;
    //     derivative = error - prevError;
    //     double outL = (error * lkP + derivative * lkD + integral * lkI);
    //     double outR = (error * kP + derivative * kD + integral * kI);

    //     if (fabs(outR) > maxRPM) outR = sign(outR) * maxRPM;
    //     if (fabs(outR) < minRPM) outR = sign(outR) * minRPM;

    //     if (fabs(outL) > maxRPM) outL = sign(outL) * maxRPM;
    //     if (fabs(outL) < minRPM) outL = sign(outL) * minRPM;

    //     // if (fabs(out) < exitMEOW) out = 0;

    //     // LeftDT.move_velocity(out);
    //     // RightDT.move_velocity(out);
    //     LeftDT.move_voltage(outL * 20);
    //     RightDT.move_voltage(outR * 20);


    //     prevError = error;
    //     // prevErrorR = error;
    //     pros::delay(10);
    // }

    // LeftDT.move_voltage(0);
    // RightDT.move_voltage(0);
}


void swervePID(double targetX, double targetY, int sec, int minRPM = 0, int maxRPM = 600){
    double start = pros::millis();

    double Kp = 1.442225, Ki = 0.000075, Kd = 4;

    LeftDT.tare_position_all();
    RightDT.tare_position_all();

    double avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2)) * 100;
    double avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2)) *100;

    double r = (pow(targetX, 2) + pow(targetY, 2)) / targetX;
    double theta = atan2(targetY, targetX);

    double distanceLeft = (r + LEFT_DT_OFFSET) * theta;
    double distanceRight = (r - RIGHT_DT_OFFSET) * theta;

    int tValRight = dToT(distanceRight);
    int tValLeft = dToT(distanceLeft);

    int errorLeft = tValLeft - avgLeftSide;
    int errorRight = tValRight - avgRightSide;


    int prevErrorLeft = errorLeft;
    int prevErrorRight = errorRight;

    int derivativeLeft;
    int derivativeRight;

    double integralRight = 0;
    double integralLeft = 0;

    while(fabs(errorLeft) > 1.7 && fabs(errorRight) > 1.7){

        if((pros::millis() - start) > sec) break;
        
        integralLeft += errorLeft;
        integralRight += errorRight;

        if (fabs(integralLeft) > 300) integralLeft = sign(integralLeft) * 300;
        if (fabs(integralRight) > 300) integralRight = sign(integralRight) * 300; 

        if (fabs(errorLeft) < 1) integralLeft = 0;
        if (fabs(errorRight) < 1) integralRight = 0;

        avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))*100;
        avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))*100;

        int tValRight = dToT(distanceRight);
        int tValLeft = dToT(distanceLeft);

        errorLeft = tValLeft - avgLeftSide;
        errorRight = tValRight - avgRightSide;

        derivativeLeft = errorLeft - prevErrorLeft;
        derivativeRight = errorRight - prevErrorRight;

        double outLeft = (errorLeft * Kp + derivativeLeft * Kd + integralLeft * Ki);
        double outRight = (errorRight * Kp + derivativeRight * Kd + integralRight * Ki);

        // if (fabs(outLeft) > maxRPM) outLeft = sign(outLeft) * maxRPM;
        // if (fabs(outLeft) < minRPM) outLeft = sign(outLeft) * minRPM;
        
        // if (fabs(outLeft) < exitMEOW) outLeft = 0;

        // if (fabs(outRight) > maxRPM) outRight = sign(outRight) * maxRPM;
        // if (fabs(outRight) < minRPM) outRight = sign(outRight) * minRPM;

        // if (fabs(outRight) < exitMEOW) outRight = 0;

        double maxVelocity = fmax(fabs(outRight), fabs(outLeft));
        double minVelocity = fmin(fabs(outRight), fabs(outLeft));

        if (maxVelocity > maxRPM){
            outRight *= maxRPM / maxVelocity;
            outLeft *= maxRPM / maxVelocity;
        }

        if (minVelocity < minRPM){
            outRight *= minRPM / minVelocity;
            outLeft *= minRPM / minVelocity;
        }

        LeftDT.move_voltage(outLeft);
        RightDT.move_voltage(outRight);


        prevErrorLeft = errorLeft;
        prevErrorRight = errorRight;

        pros::delay(10);
    }

    LeftDT.brake();
    RightDT.brake();
}

// // void ignorethisplease(double distance, int sec){
// //     double start = pros::millis();
// //     double kP = 0.1997, kI = 0.00009, kD = 0.15;
    
// //     dtFLMotor.tare_position();
// //     dtFRMotor.tare_position();
// //     dtBLMotor.tare_position();
// //     dtBRMotor.tare_position();
// //     dtTLMotor.tare_position();
// //     dtTRMotor.tare_position();

// //     int prevError = 0;
// //     int derivative;
// //     double integral = 0;
// //     double avgLeftSide = (dtFLMotor.get_position() + dtTLMotor.get_position() + dtBLMotor.get_position())/3;
// //     double avgRightSide = (dtFRMotor.get_position() + dtTRMotor.get_position() + dtBRMotor.get_position())/3;
// //     double totalAvgPos = (avgLeftSide + avgRightSide)/2;

// //     int tVal = dToT(distance);

// //     int error = tVal - totalAvgPos;
// //     while(fabs(error) > 1.7){
// //         if((pros::millis() - start) > sec) break;
// //         integral += error;

// //         if(error == 0){
// //             integral = 0;
// //         }
// //         if(integral > 300) integral = 300;
// //         if(integral < -300) integral = -300;

// //         avgLeftSide = (dtFLMotor.get_position() + dtTLMotor.get_position() + dtBLMotor.get_position())/3;
// //         avgRightSide = (dtFRMotor.get_position() + dtTRMotor.get_position() + dtBRMotor.get_position())/3;
// //         totalAvgPos = (avgLeftSide + avgRightSide)/2;

// //         error = tVal - totalAvgPos;
// //         derivative = error - prevError;
// //         double motorPower = (error * kP + derivative * kD + integral * kI);
        
// //         dtFLMotor.move_velocity(motorPower);
// //         dtBLMotor.move_velocity(motorPower);
// //         dtTLMotor.move_velocity(motorPower);
// //         dtFRMotor.move_velocity(motorPower);
// //         dtBRMotor.move_velocity(motorPower);
// //         dtTRMotor.move_velocity(motorPower);

// //         prevError = error;
// //         delay(10);
// //     }
// //     //master.print(0, 1, "Time: %.0f", (pros::millis() - start));
// // }

// // void movePID(double targetDistance, int sec){
// //     double start = pros::millis();
// //     double Kp = 0.5, Ki = 0.00015, Kd = 0.3275;
// //     double pi = 2*acos(0.0);
// //     double error = targetDistance * 91.1/pi;
// //     double integral = 0;
// //     double lastError = error;

// //     // dtFLMotor.tare_position();
// //     // dtFRMotor.tare_position();
// //     // dtBLMotor.tare_position();
// //     // dtBRMotor.tare_position();
// //     // dtTLMotor.tare_position();
// //     // dtTRMotor.tare_position();

// //     while (fabs(error) > 1) {
// //         double averagePosition = (dtFLMotor.get_position() + dtFRMotor.get_position())/2;
// //         error = averagePosition - targetDistance * 91.1/pi;
// //         integral += error;
// //         if(error == 0){
// //             integral = 0;
// //         }
// //         if(integral > 300) integral = 300;
// //         if(integral < -300) integral = -300;
// //         dtFLMotor.move_velocity(-(error*Kp + integral*Ki + (lastError-error)*Kd) * 0.75);
// //         dtBLMotor.move_velocity(-(error*Kp + integral*Ki + (lastError-error)*Kd) * 0.75);
// //         dtTLMotor.move_velocity(-(error*Kp + integral*Ki + (lastError-error)*Kd) * 0.75);
// //         dtFRMotor.move_velocity(-(error*Kp + integral*Ki + (lastError-error)*Kd) * 0.75);
// //         dtBRMotor.move_velocity(-(error*Kp + integral*Ki + (lastError-error)*Kd) * 0.75);
// //         dtTRMotor.move_velocity(-(error*Kp + integral*Ki + (lastError-error)*Kd) * 0.75);
// //         lastError = error;
// //         pros::delay(10);
// //         if((pros::millis() - start) > sec){
// //             break;
// //         }
// //     }
    
// // }

// // void pidMove(double distance) {
// //   distance *= 51.156946; // ticks
// //   double velocity = 3.75; // ticks per 5 ms
// //   double targetHeading = imu.get_heading();

// //   double leftDistance = 0;
// //   double rightDistance = 0;
// //   double leftConstant = 1;
// //   double rightConstant = 1;
// //   int completedDriveStates = 0;

// //   int iteration = 0;

// //   dtFLMotor.tare_position();
// //   dtFRMotor.tare_position();
// //   dtBLMotor.tare_position();
// //   dtBRMotor.tare_position();
// //   dtTLMotor.tare_position();
// //   dtTRMotor.tare_position();

// //   while (completedDriveStates < 25) {
// //     if (iteration % 100 == 0) master.print(0, 1, "L: %.1f R %.1f", distance - leftDistance, distance - rightDistance);
// //     iteration++;
// //     if (master.get_digital(DIGITAL_RIGHT)) break; //emergency button
// //     delay(5);
    
// //     leftDistance += (drivetrainFLMotor.get_position() + drivetrainBLMotor.get_position()) / 2;
// //     rightDistance += (drivetrainFRMotor.get_position() + drivetrainBRMotor.get_position()) / 2;
// //     double curHeading = imu.get_heading();

// //     if (fabs(distance - leftDistance) < 30 && fabs(distance - rightDistance) < 30) completedDriveStates++;
// //     else completedDriveStates = 0;

// //     if (fabs(distance - leftDistance) < fabs(distance) * 0.2) leftConstant = 0.08;
// //     else leftConstant = 1;

// //     if (fabs(distance - rightDistance) < fabs(distance) * 0.2) rightConstant = 0.08;
// //     else rightConstant = 1;

// //     // if (fabs(distance - leftDistance) < 5) {
// //     //   drivetrain.FLPID.integral = 0;
// //     //   drivetrain.BLPID.integral = 0;
// //     // }

// //     // if (fabs(distance - rightDistance) < 5) {
// //     //   drivetrain.FRPID.integral = 0;
// //     //   drivetrain.BRPID.integral = 0;
// //     // }

// //     drivetrain.pidLeftPosition(fmin(velocity * leftConstant, fabs(distance - leftDistance)) * sign(distance - leftDistance) + (curHeading - targetHeading) * 0.01 * leftConstant);
// //     drivetrain.pidRightPosition(fmin(velocity * rightConstant, fabs(distance - rightDistance)) * sign(distance - rightDistance) - (curHeading - targetHeading) * 0.01 * rightConstant);
// //   }

// //   botActiveBreak();
// // }

#endif