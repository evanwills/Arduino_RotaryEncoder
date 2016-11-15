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
	_clkPin = clockPin;
	_dtPin = dataPin;

	pinMode(_clkPin, INPUT);
	pinMode(_dtPin, INPUT);
}


long RotaryEncoder::getPosition(long startPosition, int increment = 1) {
	int clkValue = digitalRead(_clkPin);

	if ((_previousClkValue == LOW) && (clkValue == HIGH)) {
		if (digitalRead(_dtPin) == LOW) {
			startPosition -= increment;
		} else {
			startPosition += increment;
		}
		Serial.print(startPosition);
		Serial.println();
	}
	_previousClkValue = clkValue;

	return startPosition;
}

long RotaryEncoder::getPositionLimited(long startPosition, long min, long max, int increment = 1) {
//	if( min >= max) {
//		throw "getPositionLimited() expects min to be less than max";
//	}
	long endPosition = getPosition(startPosition, increment);
	if (endPosition > max) {
		endPosition = max;
	} else if (endPosition < min) {
		endPosition = min;
	}
	return endPosition;
}

long RotaryEncoder::getPositionWrap(long startPosition, long min, long max, int increment = 1) {
//	if( min >= max) {
//		throw "getPositionWrap() expects min to be less than max";
//	}
	long endPosition = getPosition(startPosition, increment);
	while (endPosition > max) {
		endPosition = (((endPosition - max) + min));
	}
	while (endPosition <= min) {
		endPosition = (max - (min - endPosition));
	}

	return endPosition;
}

//long RotaryEncoder::getPositionBounce(long startPosition, long min, long max, int increment = 1) {
////	if( min >= max) {
////		throw "getPositionLoopAround() expects min to be less than max";
////	}
//	long endPosition = getPosition(startPosition, increment);
//	while (endPosition > max) {
//		endPosition = (( endPosition - max ) + min );
//	}
//	while (endPosition < min) {
//		endPosition = ( max - ( min - endPosition ));
//	}
//	return endPosition;
//}



//  END:  (basic) RotaryEncoder class
// ========================================================





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

long BtnRotaryEncoder::getPositionLimited(long startPosition, long min, long max, int increment = 1) {
	return _encoder.getPositionLimited(startPosition, min, max, increment);
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



