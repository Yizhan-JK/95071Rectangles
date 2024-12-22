#include "main.h"

#include "functions.hpp"
#include "tasks.hpp"
#include "autonomous.hpp"

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
	lift_task.suspend();
	header_file_task.suspend();

	pros::lcd::initialize();

	LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	LiftRotation.reset();
	
	pros::lcd::set_text(1, "=^owo^=");

	pros::lcd::print(3, "lift task: %d", lift_task.get_state());
	pros::lcd::print(6, "header file task: %d", header_file_task.get_state());

	start = pros::Clock::now();

	while (true){
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) break;
	}
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
void autonomous() {}

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

	lift_task.resume();
	header_file_task.resume();

	pros::Task main_file_task([&](){
		while (true){
			pros::lcd::print(8, "hi im main file task! meow");
			pros::delay(25);
		}
	}, "main file task");

	while (true) {
		
		moveLift();

		pros::lcd::print(3, "lift task: %d", lift_task.get_state());
		pros::lcd::print(4, "lift mode: %d, lift target: %d", liftMode, liftTarget);

		pros::lcd::print(6, "header file task: %d", header_file_task.get_state());
		pros::lcd::print(7, "main file task: %d", main_file_task.get_state());

		pros::lcd::print(10, "current task: %s", pros::Task::current().get_name());

		pros::delay(10);
	}
}