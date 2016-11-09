#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>


/**
#include "RotaryEncoder.h"

Adafruit_SSD1306 OLEDScreen(4); //OLED_RESET

RotaryEncoder encoder(49, 47);
//
//ToggleButton toggleButton(45);
//BtnRotaryEncoder encoder(49, 47, toggleButton);



void setup() {
//	toggleButton.makePinModePullup();

	OLEDScreen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	OLEDScreen.clearDisplay();

	OLEDScreen.setTextColor(WHITE);
	OLEDScreen.setTextSize(1);
}

void loop() {
	OLEDScreen.clearDisplay();

	// Write "Hello" in small
	OLEDScreen.setCursor(0, 0);
	OLEDScreen.print("Testing"); //this copies some text to the screens memory
	OLEDScreen.setCursor(16, 12);
	OLEDScreen.print("BtnRotaryEncoder"); //this copies some text to the screens memory

	OLEDScreen.setCursor(32, 40);
	OLEDScreen.print("pos: ");

	long pos = encoder.getPosition();

	OLEDScreen.print(pos);

	// printing encoder button state seems to break whole sketch
//	OLEDScreen.setCursor(24, 54);
//	OLEDScreen.print("btn: ");
//
//	int state = encoder.getState();
//
//	OLEDScreen.print(state);



	OLEDScreen.display();
}
*/

Adafruit_SSD1306 OLEDScreen(4); //OLED_RESET

// Default configurations for stepper motor control
const int MAX_SPEED = 50;
const long MAX_DISTANCE = 10;
const int ACCELERATION = 100;

int rotaryMode = 0;
// holds the increment amount that the rotary controller uses
int rotaryIncrement = 1;

byte rotaryEncoderClkPin = 49;
byte rotaryEncoderDtPin = 47;

int rotaryEncoderClkValue;
int rotaryEncoderDtValue;
int rotaryEncoderClkValuePrevious;

// These are settings captured by the UI settings
long setting_right_wheel_distance = 93;	// in mm
long setting_right_wheel_speed = 25;	// arbitrary scale
long setting_left_wheel_speed = 35;		// in mm
long setting_left_wheel_distance = 100;	// arbitrary scale
long pos = 0;





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
  }

  rotaryEncoderClkValuePrevious = rotaryEncoderClkValue; // Don’t forget this
}


void setup() {
	OLEDScreen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	OLEDScreen.clearDisplay();

	OLEDScreen.setTextColor(WHITE);
	OLEDScreen.setTextSize(1);

	pinMode(rotaryEncoderClkPin, INPUT); // clk
	pinMode(rotaryEncoderDtPin, INPUT); // dt
}

void loop() {
	OLEDScreen.clearDisplay();

	// Write "Hello" in small
	OLEDScreen.setCursor(0, 0);
	OLEDScreen.print("Testing"); //this copies some text to the screens memory

	OLEDScreen.setCursor(16, 12);
	OLEDScreen.print("BtnRotaryEncoder"); //this copies some text to the screens memory

	OLEDScreen.setCursor(32, 40);
	OLEDScreen.print("tmp: ");

	readRotaryEncoders();

	OLEDScreen.print(setting_right_wheel_distance);
	OLEDScreen.display();
}