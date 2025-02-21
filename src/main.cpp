
#include "main.h"

#include "functions.hpp"
#include "tasks.hpp"
#include "autonomous.hpp"


void on_center_button() {}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	master.clear();

	odom_task.suspend();
	auton_drive_task.suspend();
	lift_task.suspend();
	color_task.suspend();
	print_task_lcd.suspend();
	// print_task_auton.suspend();

	calibrate();
	
	pros::lcd::initialize();
	pros::lcd::set_text(1, "=^owo^=");

	IntakeFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	IntakeBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	LiftRotation.set_position(0);

	OpticalSensor.set_led_pwm(100);

	ColorPiston.extend();

	autonSelect();

	odom_task.resume();
	auton_drive_task.resume();

	preAuton();

	odom_task.suspend();
	auton_drive_task.suspend();
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

	odom_task.resume();
	auton_drive_task.resume();
	lift_task.resume();
	print_task_lcd.resume();

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
		autonSkills();
		break; 
	}

	odom_task.suspend();
	auton_drive_task.suspend();
	lift_task.suspend();
	print_task_lcd.suspend();
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

	odom_task.resume();
	color_task.resume();
	lift_task.resume();
	print_task_lcd.resume();

	while (true) {

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
			pros::delay(300);
			if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
				auton_drive_task.resume();
				autonomous();
				auton_drive_task.suspend();
			}
		}

		moveDT();
		moveIntake();
		moveLift();
		togglePneumatics();
		liftManuel();
		colorModeSwitch();
		liftModeSwitch();

		pros::delay(10);
	}
}