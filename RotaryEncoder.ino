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

RotaryEncoder encoder(rotaryEncoderClkPin, rotaryEncoderDtPin);



//  END: variable definitions
// ==================================================================
// START: doin' tha do



void setup() {
	// put your setup code here, to run once:

	// Initialise the OLED display
	// Note: it is necessary to change a value in the Adafruit_SSD1306 library to set the screen size to 128x64
	OLEDScreen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	OLEDScreen.clearDisplay();

	// Set some default values for writing to the OLED screen
	OLEDScreen.setTextColor(WHITE);
}

void loop() {
	OLEDScreen.clearDisplay();

	// Write "Hello" in small
	OLEDScreen.setTextSize(1);
	OLEDScreen.setCursor(0, 0);
	OLEDScreen.print("Testing: ");
	OLEDScreen.setCursor(23, 12);
	OLEDScreen.print("RotaryEncoder"); //this copies some text to the screens memory
	// OLEDScreen.setTextSize(1);
	OLEDScreen.setCursor(0, 24);


	OLEDScreen.print("pos: ");

	int pos = 0;
	pos = encoder.getPositionLimited(pos, -MAX_DISTANCE, MAX_DISTANCE);

	OLEDScreen.print(pos);
	OLEDScreen.display();

//	OLEDScreen.print("pabloOS function"); //this copies some text to the screens memory
//
//	OLEDScreen.setCursor(32, 40);
//	OLEDScreen.print("tmp: ");
//
//	readRotaryEncoders();
//
//	OLEDScreen.print(setting_right_wheel_distance);
	OLEDScreen.display();
}

