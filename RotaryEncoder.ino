#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#include "RotaryEncoder.h"

Adafruit_SSD1306 OLEDScreen(4); //OLED_RESET

// Default configurations for stepper motor control
const int MAX_SPEED = 50;
const long MAX_DISTANCE = 10;




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

/**

long pos = 0;

RotaryEncoder encoder(49, 47);
//
//ToggleButton toggleButton(45);



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

	pos = encoder.getPositionLimited(pos, -MAX_DISTANCE, MAX_DISTANCE);

	OLEDScreen.print(pos);

	OLEDScreen.display();
}
/*

/* */



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

/* */