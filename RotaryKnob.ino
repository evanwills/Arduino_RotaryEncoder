#include <Arduino.h>

void report() {}

/*
  Handles the rotary controller
*/

void setupRotaryEncoder(){
  pinMode(rotaryEncoderClkPin, INPUT); // clk
  pinMode(rotaryEncoderDtPin, INPUT); // dt
//  rotaryEncoderBtn.makePinModePullup(); // btn
}

/*
 * This method reads all the rotary encoders
 */
void readRotaryEncoders() {
  rotaryEncoderClkValue = digitalRead(rotaryEncoderClkPin); // orange cable, CLK
  rotaryEncoderDtValue = digitalRead(rotaryEncoderDtPin);

  // rotaryMode; // Can be 0 1 2 or 3 (depending on which value we are changing)

  if ((rotaryEncoderClkValue != rotaryEncoderClkValuePrevious) && (rotaryEncoderClkValue == LOW)) { // Knob Rotated l when aVal changes, BUT use only if aVal is LOW.
    if (rotaryEncoderDtValue == LOW) {
      // INCREMENT
      if (rotaryMode == 0) {
        setting_right_wheel_distance += rotaryIncrement;
        if (setting_right_wheel_distance > MAX_DISTANCE) {
			setting_right_wheel_distance = MAX_DISTANCE;
		}
      }
      else if (rotaryMode == 1) {
        setting_right_wheel_speed += 1;
        if (setting_right_wheel_speed > MAX_SPEED) {
			setting_right_wheel_speed = MAX_SPEED;
		}
      }
      else if (rotaryMode == 2) {
        setting_left_wheel_speed += 1;
        if (setting_left_wheel_speed > MAX_SPEED) {
			setting_left_wheel_speed = MAX_SPEED;
		}
      }
      else {
        setting_left_wheel_distance += rotaryIncrement;
        if (setting_left_wheel_distance > MAX_DISTANCE) {
			setting_left_wheel_distance = MAX_DISTANCE;
		}
      }
    }
    else {
      // DECREMENT
      if (rotaryMode == 0) {
		if (setting_right_wheel_distance < -MAX_DISTANCE) {
		  setting_right_wheel_distance = -MAX_DISTANCE;
		}
        setting_right_wheel_distance -= rotaryIncrement;
      }
      else if (rotaryMode == 1) {
        setting_right_wheel_speed -= 1;
        if (setting_right_wheel_speed < -MAX_SPEED) {
			setting_right_wheel_speed = -MAX_SPEED;
		}
      }
      else if (rotaryMode == 2) {
        setting_left_wheel_speed -= 1;
        if (setting_left_wheel_speed < -MAX_SPEED) {
			setting_left_wheel_speed = -MAX_SPEED;
		}
      }
      else {
        setting_left_wheel_distance -= rotaryIncrement;
  		if (setting_left_wheel_distance < -MAX_DISTANCE) {
  		  setting_left_wheel_distance = -MAX_DISTANCE;
  		}
      }
    }
	report();
  }

  rotaryEncoderClkValuePrevious = rotaryEncoderClkValue; // Don't forget this
}

void cycleRotaryIncrement(){
  if (rotaryIncrement == 1) {
    rotaryIncrement = 10;
  }
  else if (rotaryIncrement == 10) {
    rotaryIncrement = 100;
  }
  else if (rotaryIncrement == 100) {
    rotaryIncrement = 1000;
  }
  else if (rotaryIncrement == 1000) {
    rotaryIncrement = 1;
  }
}
