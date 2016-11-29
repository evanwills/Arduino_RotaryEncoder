#include "RotaryEncoder.h"


// ========================================================
// START: (basic) RotaryEncoder class

//	protected:
//		byte _clkPin;
//		byte _dtPin;
//		int _clkValue;
//		int _dtValue;
//		long _position;
//		int _previousClkValue;
//		int _increment = 1;


RotaryEncoder::RotaryEncoder( byte clockPin , byte dataPin ) {
	RotaryEncoder::_clkPin = clockPin;
	RotaryEncoder::_dtPin = dataPin;

	pinMode(RotaryEncoder::_clkPin, INPUT);
	pinMode(RotaryEncoder::_dtPin, INPUT);
}


void RotaryEncoder::ISR_UpdatePosition() {
	int clkValue = digitalRead(RotaryEncoder::_clkPin);

	if ((RotaryEncoder::_previousClkValue == LOW) && (clkValue == HIGH)) {
		if (digitalRead(RotaryEncoder::_dtPin) == LOW) {
			RotaryEncoder::_pos -= 1;
		} else {
			RotaryEncoder::_pos += 1;
		}
		Serial.print(RotaryEncoder::_pos);
		Serial.println();
	}
	RotaryEncoder::_previousClkValue = clkValue;
}

long RotaryEncoder::getPosition(long startPosition, int increment = 1) {
	startPosition *= (RotaryEncoder::_pos * increment);
	RotaryEncoder::_pos = 0;
	return startPosition;
}

long RotaryEncoder::getPositionLimit(long startPosition, long min, long max, int increment = 1) {
//	if( min >= max) {
//		throw "getPositionLimit() expects min to be less than max";
//	}
	if (min > max) {
		long tmp = min;
		min = max;
		max = tmp;
		// TODO: work out how to unset tmp variable
	}

	max -= 1;
	min += 1;

	startPosition = getPosition(startPosition, increment);

	if (startPosition > max) {
		startPosition = max;
	} else if (startPosition < min) {
		startPosition = min;
	}
	return startPosition;
}

long RotaryEncoder::getPositionWrap(long startPosition, long min, long max, int increment = 1) {
//	if( min >= max) {
//		throw "getPositionWrap() expects min to be less than max";
//	}
	if (min > max) {
		long tmp = min;
		min = max;
		max = tmp;
		// TODO: work out how to unset tmp variable
	}

	startPosition = getPosition(startPosition, increment);

	while (startPosition > max) {
		startPosition = (((startPosition - max) + min));
	}
	while (startPosition <= min) {
		startPosition = (max - (min - startPosition));
	}

	return startPosition;
}

//long RotaryEncoder::getPositionBounce(long startPosition, long min, long max, int increment = 1) {
////	if( min >= max) {
////		throw "getPositionLoopAround() expects min to be less than max";
////	}
//
//	startPosition = getPosition(startPosition, increment);
//
//	while (startPosition > max) {
//		startPosition = (( startPosition - max ) + min );
//	}
//	while (startPosition < min) {
//		startPosition = ( max - ( min - startPosition ));
//	}
//	return startPosition;
//}


void RotaryEncoder::startStopListening() {
	RotaryEncoder::_active = !RotaryEncoder::_active;

	RotaryEncoder::_previousClkValue = 0;
	RotaryEncoder::_pos = 0;

	if (RotaryEncoder::_active == true) {
		attachInterrupt(digitalPinToInterrupt(RotaryEncoder::_clkPin), RotaryEncoder::ISR_UpdatePosition, CHANGE);
	} else {
		detachInterrupt(digitalPinToInterrupt(RotaryEncoder::_clkPin));
	}
}



//  END:  (basic) RotaryEncoder class
// ========================================================


bool RotaryEncoder::_active = false;


/**

// ========================================================
// START: BtnRotaryEncoder class



BtnRotaryEncoder::BtnRotaryEncoder(  RotaryEncoderInteface& encoder , StatefulButtonInterface& button ) {
	_encoder = encoder;
	_btn = button;
}

long BtnRotaryEncoder::getPosition(long startPosition, int increment = 1) {
	return _encoder.getPosition(startPosition, increment);
}

long BtnRotaryEncoder::getPositionLimit(long startPosition, long min, long max, int increment = 1) {
	return _encoder.getPositionLimit(startPosition, min, max, increment);
}

long BtnRotaryEncoder::getPositionLoopAround(long startPosition, long min, long max, int increment = 1) {
	return _encoder.getPositionLoopAround(startPosition, min, max, increment);
}

bool BtnRotaryEncoder::isPressed() {
	return _btn.isPressed();
}

int BtnRotaryEncoder::getState() {
	return _btn.getState();
}

//  END:  BtnRotaryEncoder interface
// ========================================================

*/



