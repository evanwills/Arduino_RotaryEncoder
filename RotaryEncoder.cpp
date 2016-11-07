#include "RotaryEncoder.h"


// ========================================================
// START: (basic) RotaryEncoder class

//
//	protected:
//		byte _clkPin;
//		byte _dtPin;
//		int _clkValue;
//		int _dtValue;
//		long _position;
//		int _previousClkValue;
//		unsigned int increment = 1;

RotaryEncoder::RotaryEncoder( byte clockPin , byte dataPin ) {
	_clkPin = clockPin;
	_dtPin = dataPin;

	pinMode(_clkPin, INPUT); // clk
	pinMode(_dtPin, INPUT); // dt
}


long RotaryEncoder::getPosition() {
	_clkValue = digitalRead(_clkPin);
	_dtValue  = digitalRead(_dtPin);

	if ((_clkValue != _previousClkValue) && (_clkValue != LOW)) {
		if (_dtValue == LOW) {
			_position += _increment;
		} else {
			_position -= _increment;
		}
	}
	_previousClkValue = _clkValue;
	return _position;
}


long RotaryEncoder::getPosition(unsigned int tempIncrement) {
	unsigned int tmp = _increment;
	_increment = tempIncrement;
	long output = getPosition();
	_increment = tmp;
	return output;
}

void RotaryEncoder::setPosition( long newPosition ) {
	_position = newPosition;
}

unsigned int RotaryEncoder::getIncrement() {
	return _increment;
}

void RotaryEncoder::setIncrement( unsigned int newIncrement ) {
	_increment = newIncrement;
}


//  END:  (basic) RotaryEncoder class
// ========================================================
// START: BtnRotaryEncoder class



BtnRotaryEncoder::BtnRotaryEncoder(  byte clockPin , byte dataPin , SimpleButton& button ) : RotaryEncoder( clockPin , dataPin ) {
	_btn = button;
}


bool BtnRotaryEncoder::isPressed() {
	return _btn.isPressed();
}

int BtnRotaryEncoder::getState() {
	return _btn.getState();
}


//  END:  BtnRotaryEncoder class
// ========================================================