#include "main.h"
#include "motor.h"
#include <sstream>
#include <stdio.h>

/*pros::Motor arm_motor(ARM_MOTOR_PORT);
pros::Motor claw_motor(CLAW_MOTOR_PORT);

pros::Motor bot_left_wheel(BOT_LEFT_WEEL_PORT);
pros::Motor top_left_wheel(TOP_LEFT_WEEL_PORT);
pros::Motor bot_right_wheel(BOT_RIGHT_WEEL_PORT, true); // This reverses the motor
pros::Motor top_right_wheel(TOP_RIGHT_WEEL_PORT, true);
*/

pros::Motor left_wheels(LEFT_WHEELS_PORT);
pros::Motor right_wheels(RIGHT_WHEELS_PORT, true); // This reverses the motor

pros::Motor claw(4);
pros::Motor elevator(3);

pros::ADIDigitalIn high_arm_limit('a');
pros::ADIDigitalIn low_arm_limit('b');

pros::Controller master(CONTROLLER_MASTER);

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Alejandro is bad");

	pros::lcd::register_btn1_cb(on_center_button);
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

void move_forward_idk() {
	// This code is awful and i'm pretty sure it won't work
	for (int i = 0; i < /*150000*/ 99996; i++) {
		left_wheels.move(127);
		right_wheels.move(127);
	}
}
/*
void move_backward() {
	// This code is awful and i'm pretty sure it won't work
	for (int i = 0; i < 10000; i++) {
		bot_left_wheel.move(-127);
		top_left_wheel.move(-127);
		bot_right_wheel.move(-127);
		top_right_wheel.move(-127);
	}
}

void rotate_left() {
	// This code is awful and i'm pretty sure it won't work
	for (int i = 0; i < 10000; i++) {
		bot_left_wheel.move(-127);
		top_left_wheel.move(-127);
		bot_right_wheel.move(127);
		top_right_wheel.move(127);
	}
}

void rotate_right() {
	// This code is awful and i'm pretty sure it won't work
	for (int i = 0; i < 10000; i++) {
		bot_left_wheel.move(127);
		top_left_wheel.move(127);
		bot_right_wheel.move(-127);
		top_right_wheel.move(-127);
	}
}

void arm_up() {
	// This code is awful and i'm pretty sure it won't work
	for (int i = 0; i < 10000; i++) {
		arm_motor.move(127);
	}
}

void arm_down() {
	// This code is awful and i'm pretty sure it won't work
	for (int i = 0; i < 10000; i++) {
		arm_motor.move(-127);
	}
}*/

void move_forward_1ft() {
	printf("Poggers\n");
	move_forward_idk();
}

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
//void autonomousLeft() {
//	for (int i = 0; i < 80; i++) {
//		arm_up();
//	}
//	for (int i = 0; i < 24; i++) {
//		move_forward();
//	}
//	for (int i = 0; i < 90; i++) {
//		rotate_right();
//	}
//	for (int i = 0; i < 14; i++) {
//		move_forward();
//	}
//	for (int i = 0; i < 45; i++) {
//		arm_down();
//	}
//	for (int i = 0; i < 7; i++) {
//		claw_close();
//	}
//	//this has the robot grab a ring
//	for (int i = 0; i < 115; i++) {
//		arm_up();
//	}
//	for (int i = 0; i < 90; i++) {
//		rotate_left();
//	}
//	for (int i = 0; i < 12; i++) {
//		move_forward();
//	}
//	for (int i = 0; i < 100; i++) {
//		arm_down();
//	}
//	for (int i = 0; i < 7; i++) {
//		claw_open();
//	}
//	for (int i = 0; i < 12; i++) {
//		move_backward();
//	}
//	//this has the robote put a ring on a goal
//}
//void autonomousRight() {
//	for (int i = 0; i < 80; i++) {
//		arm_up();
//	}
//	for (int i = 0; i < 42; i++) {
//		move_forward();
//	}
//	for (int i = 0; i < 90; i++) {
//		rotate_left();
//	}
//	for (int i = 0; i < 7; i++) {
//		move_forward();
//	}
//	for (int i = 0; i < 45; i++) {
//		arm_down();
//	}
//	for (int i = 0; i < 7; i++) {
//		claw_close();
//	}
//	//this has the robot grab a ring
//	for (int i = 0; i < 115; i++) {
//		arm_up();
//	}
//	for (int i = 0; i < 90; i++) {
//		rotate_right();
//	}
//	for (int i = 0; i < 18; i++) {
//		move_forward();
//	}
//	for (int i = 0; i < 100; i++) {
//		arm_down();
//	}
//	for (int i = 0; i < 7; i++) {
//		claw_open();
//	}
//	for (int i = 0; i < 12; i++) {
//		move_backward();
//	}
//	//this has the robote put a ring on a goal
//}


/*pros::ADIButton goalGrabberLimitSwitchUno('A');
pros::ADIButton goalGrabberLimitSwitchDos('B');
pros::Motor goalGrabberMotor(GOAL_GRABBER_PORT);

int isUp = 1;

void toggleArm() {
	while(!goalGrabberLimitSwitchUno.isPressed() || !goalGrabberLimitSwitchDos.isPressed()) {
		goalGrabberMotor.move_voltage(12000);
	}
}*/


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

int pressed = 0;

void opcontrol() {

	int isDown = 0;

	while (true) {
		left_wheels.move(master.get_analog(ANALOG_LEFT_Y));
		right_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
		
		// CLAW
		if (low_arm_limit.get_value()) {
			claw.move(0);
		}

		if (high_arm_limit.get_value()) {
			claw.move(0);
		}

		if (master.get_digital(DIGITAL_A)) {
			claw.move(12000);
		}

		if (master.get_digital(DIGITAL_B)) {
			claw.move(-12000);
		}
		//CLAW END

		if (master.get_digital(DIGITAL_R1)) {
			if (pressed) return;

			move_forward_1ft();
			pressed = 1;
		}

		if (master.get_digital(DIGITAL_L1)) {
			pressed = 0;
		}

		if (!master.get_digital(DIGITAL_X)) {
			elevator.move(0);
		}

		if (master.get_digital(DIGITAL_X)) {
			elevator.move(-127);
		}

		if (!master.get_digital(DIGITAL_Y))
			elevator.move(0);

		if (master.get_digital(DIGITAL_Y))
			elevator.move(-127);

		/*if (master.get_digital(DIGITAL_Y)) {
			printf("%i", arm_limit.get_value());
		}*/

		pros::delay(2);
	}
}
