#include RotaryEncoder.h


// ========================================================
// START: (basic) RotaryEncoder class

//
//	protected:
//		byte clkPin;
//		byte dtPin;
//		int clk_value;
//		int dt_value;
//		long position;
//		int previous_clk_value;
//		unsigned int increment = 1;

RotaryEncoder::RotaryEncoder( int clockPin , int dataPin ) {
	clkPin = clockPin;
	dtPin = dataPin;
	position = defaultPos;

	pinMode(clkPin, INPUT); // clk
	pinMode(dtPin, INPUT); // dt
}


long RotaryEncoder::getPosition( bool doRead ) {
	clk_value = digitalRead(clkPin);
	dt_value  = digitalRead(dtPin);

	if ((clk_value != previous_clk_value) && (clk_value != LOW)) {
		if (dt_value == LOW) {
			position += increment;
		} else {
			position -= increment;
		}
	}
	previous_clk_value = clk_value;
	return position;
}

void RotaryEncoder::setPosition( long newPosition ) {
	position = newPosition;
}

unsigned int RotaryEncoder::getIncrement( ) {
	return increment;
}

void RotaryEncoder::setIncrement( unsigned int newIncrement ) {
	increment = newIncrement;
}

//  END:  (basic) RotaryEncoder class
// ========================================================
// START: BtnRotaryEncoder class

BtnRotaryEncoder::BtnRotaryEncoder(  int clockPin , int dataPin , ITimedButton button ) {
	clkPin = clockPin;
	dtPin = dataPin;
	position = defaultPos;
	btn = button;

	pinMode(clkPin, INPUT); // clk
	pinMode(dtPin, INPUT); // dt
}


bool BtnRotaryEncoder::readButton() {
	return btn->readButton();
}

int BtnRotaryEncoder::pressed() {
	return btn->pressed();
}


//  END:  BtnRotaryEncoder class
// ========================================================