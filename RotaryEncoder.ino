#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>


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
