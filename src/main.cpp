#include "main.h"

#include "functions.hpp"
#include "tasks.hpp"
#include "autonomous.hpp"
#include "chassis_setup.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	master.clear();

	lift_task.suspend();
	color_task.suspend();
	// print_task_auton.suspend();
	// print_task_drive.suspend();

	Chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

	IntakeFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	IntakeBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	LiftRotation.set_position(0);

	IntakeBMotor.tare_position();

	OpticalSensor.set_led_pwm(100);

	colorPiston.retract();

	pros::lcd::initialize();
	pros::lcd::set_text(1, "=^owo^=");

	master.clear();

	Chassis.calibrate();
	// ImuSensor.reset();
	delay(500);
	Chassis.setPose(0, 0, 0);

	autonSelect();

	lift_task.resume();

	preAuton();

	color_task.resume();
	DoinkerPiston.set_value(false);
	ClampPiston.set_value(false);
	// print_task_auton.resume();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {

	
	switch (autonSelected) {
		
		case 0:
		testAuton();
		break;

		case 1:
		noAuton();
		break;

		case 2:
		colorMode = 1;
		colorSense = true;
		redPositive();
		break;

		case 3:
		colorMode = 1;
		colorSense = true;
		redNegative();
		break;

		case 4:
		colorMode = 1;
		colorSense = true;
		redAWP();
		break;

		case 5:
		colorMode = 2;
		colorSense = true;
		bluePositive();
		break;

		case 6:
		colorMode = 2;
		colorSense = true;
		blueNegative();
		break;

		case 7:
		colorMode = 2;
		colorSense = true;
		blueAWP();
		break;

		case 8:
		colorMode = 1;
		colorSense = false;
		liftMode = 1;
		autonSkills();
		break; 
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	//print_task_auton.suspend();
	opControl = true;
	liftAuto = false;
	lift_task.resume();
	// print_task_drive.resume();
	// autoClamp(false);
    // liftTarget = 16500;
    // delay(1000);
    // movePID(-9.75, 1000, 0, 350);
    // liftTarget = 0;
    // movePID(-9.5, 800, 0, 300);

	while (true) {
		
		if (master.get_digital(DIGITAL_LEFT)){
			pros::delay(100);
			if (master.get_digital(DIGITAL_LEFT)){
				//lift_task.suspend();
				opControl = false;
				liftAuto = true;
				autonomous();
				opControl = true;
				liftAuto = false;
			}
		}

		moveDT();
		moveIntake();
		moveLift();
		togglePneumatics();
		liftManuel();
		colorModeSwitch();
		//liftModeSwitch();

		pros::delay(10);
	}
}