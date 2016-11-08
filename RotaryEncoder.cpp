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
//		unsigned int _increment = 1;

RotaryEncoder::RotaryEncoder( byte clockPin , byte dataPin ) {
	_clkPin = clockPin;
	_dtPin = dataPin;

	pinMode(_clkPin, INPUT); // clk
	pinMode(_dtPin, INPUT); // dt
}


long RotaryEncoder::getPosition() {
	_clkValue = digitalRead(_clkPin);
	_dtValue = digitalRead(_dtPin);

	if ((_clkValue != _previousClkValue) && (_clkValue == LOW)) { // Knob Rotated when _clkValue changes, BUT use only if _clkValue is LOW.
		if (_dtValue == LOW) {
			// INCREMENT
			_position += _increment;
		}
		else {
			// DECREMENT
			_position -= _increment;
		}
	}

	_previousClkValue = _clkValue;
	return _position;
}


long RotaryEncoder::getPosition(unsigned int tempIncrement) {
	unsigned int tmpInc = _increment;
	_increment = tempIncrement;
	long output = getPosition();
	_increment = tmpInc;
	return output;
}

long RotaryEncoder::getPositionLimited( long min, long max) {
//	if( min >= max) {
//		throw "getPositionLimited() expects min to be less than max";
//	}
	long output = getPosition();
	if (output > max) {
		output = max;
	} else if (output < min) {
		output = min;
	}
	return output;
}

long RotaryEncoder::getPositionLimited( long min, long max, unsigned int tempIncrement ) {
	unsigned int tmpInc = _increment;
	_increment = tempIncrement;
	long output = getPositionLimited(min, max);
	_increment = tmpInc;
	return output;
}

long RotaryEncoder::getPositionLoopAround( long min, long max) {
//	if( min >= max) {
//		throw "getPositionLoopAround() expects min to be less than max";
//	}
	long output = getPosition();
	while (output > max) {
		output = ( output - max ) + min;
	}
	while (output < min) {
		output = max - ( min - output );
	}
	return output;
}

long RotaryEncoder::getPositionLoopAround( long min, long max, unsigned int tempIncrement ) {
	unsigned int tmpInc = _increment;
	_increment = tempIncrement;
	long output = getPositionLoopAround(min, max);
	_increment = tmpInc;
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





// ========================================================
// START: BtnRotaryEncoder class



BtnRotaryEncoder::BtnRotaryEncoder(  byte clockPin , byte dataPin , FlexibleButtonInterface& button ) : RotaryEncoder( clockPin , dataPin ) {
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