#ifndef PID_HPP
#define PID_HPP

#include "main.h"

class Pid {

    public:

    double kP = 0;
    double kI = 0;
    double kD = 0;

    // double target;

    double error;
    double lastError;

    double integral;
    double derivative;

    double minVelocity = 0;
    double maxVelocity = 600;

    double intLimit = 400;

    double exit = 0.01;

    Pid(double p, double i, double d) : kP(p), kI(i), kD(d) {}

    void setIntLimit (double integralLimit = 400){
        intLimit = integralLimit;
    }

    void update (double posError){
        error = posError;

        if (fabs(integral) < intLimit) integral += error;
        else integral = sign(integral) * intLimit; 

        if (fabs(error) < 1) integral = 0;

        derivative = error - lastError;
        lastError = error;
    }

    double output (){

        double out = kP * error + kI * integral + kD * derivative;

        if (fabs(out) > maxVelocity) out = sign(out) * maxVelocity;
        if (fabs(out) < minVelocity) out = sign(out) * minVelocity;

        if (fabs(out) < exit) out = 0;

        return out;
    }

    // double setTarget (double targetIn){
    //     target = targetIn;
    // }

    void resetID (){
        lastError, integral, derivative = 0;
    }

};

#endif