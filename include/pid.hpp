#ifndef PID_HPP
#define PID_HPP


#include "main.h"
#include "functions.hpp"
#include "pros/abstract_motor.hpp"

int sign (double in){
    return (in == 0) ? 0 : fabs(in) / in;
}

double exitMEOW = 0.2;

void turnPID(double targetDegrees, int sec, int minRPM = 0, int maxRPM = 600){
    double start = pros::millis();
    double Kp = 0.4925, Ki = 0.0001, Kd = 0;
    double error = targetDegrees - Imu.get_heading();
    double integral = 0;
    double lastError = error;
    double initialHeading = Imu.get_heading();

    while (fabs(error) > 1.7) {
        error = static_cast<int>(targetDegrees - Imu.get_heading() + 360) % 360;
        if(error >= 180){
            error -=  360;
        }
        integral += error;
        if(error == 0){
            integral = 0;
        }
        if(integral > 300) integral = 300;
        if(integral < -300) integral = -300;

        double out = (error*Kp + integral*Ki + (lastError-error)*Kd) *5;

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
    double kP = 1.442225, kI = 0.000075, kD = 4.6;
    
    LeftDT.tare_position_all();
    RightDT.tare_position_all();
    
    // LeftDT.set_zero_position_all(0);
    // RightDT.set_zero_position_all(0);

    int prevError = 0;
    int derivative;
    double integral = 0;
    double avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2)) * 100;
    double avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2)) *100;
    // double avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))/3;
    // double avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))/3;
    double totalAvgPos = (avgLeftSide + avgRightSide)/2;

    int tVal = dToT(distance);

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

        avgLeftSide = (LeftDT.get_position(0) + LeftDT.get_position(1) + LeftDT.get_position(2))*100;
        avgRightSide = (RightDT.get_position(0) + RightDT.get_position(1) + RightDT.get_position(2))*100;
        totalAvgPos = (avgLeftSide + avgRightSide)/2;

        error = tVal - totalAvgPos;
        derivative = error - prevError;
        double out = (error * kP + derivative * kD + integral * kI);
        
        // LeftDT.move_velocity(motorPower);
        // RightDT.move_velocity(motorPower);

        // double out = (error*Kp + integral*Ki + (lastError-error)*Kd) *5;

        if (fabs(out) > maxRPM) out = sign(out) * maxRPM;
        if (fabs(out) < minRPM) out = sign(out) * minRPM;
        
        if (fabs(out) < exitMEOW) out = 0;

        LeftDT.move_velocity(out);
        RightDT.move_velocity(out);


        prevError = error;
        pros::delay(10);
    }
    LeftDT.move_velocity(0);
    RightDT.move_velocity(0);
    // LeftDT.brake();
    // RightDT.brake();
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