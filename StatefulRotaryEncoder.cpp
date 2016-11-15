#include "StatefulRotaryEncoder.h"



// ========================================================
// START: StatefulRotaryEncoder interface

StatefulRotaryEncoderInterface::StatefulRotaryEncoderInterface(byte clockPin, byte dataPin, long min, long max, unsigned int increment = 1, long startPosition = 0) {
	_clkPin = clockPin;
	_dtPin = dataPin;
	_pos = startPostition;
	_min = min;
	_max = max;
	_increment = increment;
}

StatefulRotaryEncoderInterface::_getPoistionRaw() {
	int clkValue = digitalRead(_clkPin);

	if ((clkValue != _previousClkValue) && (clkValue == LOW)) {
		if (digitalRead(_dtPin) == LOW) {
			// INCREMENT
			_pos += _increment;
		}
		else {
			// DECREMENT
			_pos -= _increment;
		}
	}
	_previousClkValue = clkValue;
}


//  END:  StatefulRotaryEncoder interface
// ========================================================


// ========================================================
// START: StatefulLimitedRotaryEncoder interface

StatefulLimitedRotaryEncoder::StatefulLimitedRotaryEncoder(byte clockPin, byte dataPin, long min, long max, unsigned int increment = 1, long startPosition = 0) : StatefulRotaryEncoderInterface(clockPin, dataPin, min, max, increment, startPosition) {
}

long StatefulLimitedRotaryEncoder::getPosition() {
	_getPoistionRaw();
	if (_pos > _max) {
		_pos = _max;
	} else if (_pos < _min) {
		_pos = _min;
	}
	return _pos;
}
long StatefulLimitedRotaryEncoder::getPosition(unsigned int increment = 1) {
	_increment = increment;
	return getPosition();
}

//  END:  StatefulRotaryEncoderInterface interface
// ========================================================


// ========================================================
// START: StatefulLoopRotaryEncoder interface

StatefulLoopRotaryEncoder::StatefulLoopRotaryEncoder(byte clockPin, byte dataPin, long min, long max, unsigned int increment = 1, long startPosition = 0) : StatefulRotaryEncoderInterface(clockPin, dataPin, min, max, increment, startPosition) {
}

long StatefulLoopRotaryEncoder::getPosition() {
	_getPoistionRaw();
	while (_pos > max) {
		_pos = (( _pos - max ) + min );
	}
	while (_pos < min) {
		_pos = ( max - ( min - _pos ));
	}
	return _pos;
}

long StatefulLoopRotaryEncoder::getPosition(unsigned int increment = 1) {
	_increment = increment;
	return getPosition();
}

//  END:  StatefulRotaryEncoderInterface interface
// ========================================================


//// ========================================================
//// START: StatefulBounceRotaryEncoder interface
//
//StatefulBounceRotaryEncoder::StatefulBounceRotaryEncoder(byte clockPin, byte dataPin, long min, long max, unsigned int increment = 1, long startPosition = 0) : StatefulRotaryEncoderInterface(clockPin, dataPin, min, max, increment, startPosition) {
//}
//
//long StatefulBounceRotaryEncoder::getPosition() {
//	_pos = encoder.getPositionLoopAround(_pos, _min, _max, _increment);
//	return _pos;
//}
//long StatefulBounceRotaryEncoder::getPosition(unsigned int increment = 1) {
//	_increment = increment;
//	return getPosition();
//}
//
////  END:  StatefulRotaryEncoderInterface interface
//// ========================================================

