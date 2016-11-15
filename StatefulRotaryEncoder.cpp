//#include "StatefulRotaryEncoder.h"
//
//
//
//// ========================================================
//// START: StatefulRotaryEncoder interface
//
//StatefulRotaryEncoderInterface::StatefulRotaryEncoderInterface(byte clockPin, byte dataPin, long min, long max, int increment = 1, long startPosition = 0) {
//	_clkPin = clockPin;
//	_dtPin = dataPin;
//	_pos = startPosition;
////	_min = min;
////	_max = max;
//	_min = min - 2;
//	_max = max - 1;
//	_increment = increment;
//}
//
//void StatefulRotaryEncoderInterface::_getPoistionInner() {
//	int clkValue = digitalRead(_clkPin);
//
//	if ((_previousClkValue == LOW) && (clkValue == HIGH)) {
//		if (digitalRead(_dtPin) == LOW) {
//			_pos -= _increment;
//		} else {
//			_pos += _increment;
//		}
//		Serial.print(_pos);
//		Serial.println();
//	}
//
//	_previousClkValue = clkValue;
//}
//
//
////  END:  StatefulRotaryEncoder interface
//// ========================================================
//
//
//// ========================================================
//// START: StatefulLimitedRotaryEncoder interface
//
//StatefulLimitedRotaryEncoder::StatefulLimitedRotaryEncoder(byte clockPin, byte dataPin, long min, long max, int increment = 1, long startPosition = 0) : StatefulRotaryEncoderInterface(clockPin, dataPin, min, max, increment, startPosition) {
//}
//
//long StatefulLimitedRotaryEncoder::getPosition() {
//	_getPoistionRaw();
//	return _pos;
//}
//long StatefulLimitedRotaryEncoder::getPosition(int increment = 1) {
//	_increment = increment;
//	_getPoistionRaw();
//	return _pos;
//}
//
//void StatefulLimitedRotaryEncoder::_getPoistionInner() : _getPoistionInner() {
//	if (_pos > _max) {
//		_pos = _max;
//	} else if (_pos < _min) {
//		_pos = _min;
//	}
//}
//
////  END:  StatefulRotaryEncoderInterface interface
//// ========================================================
//
//
//// ========================================================
//// START: StatefulLoopRotaryEncoder interface
//
//StatefulLoopRotaryEncoder::StatefulLoopRotaryEncoder(byte clockPin, byte dataPin, long min, long max, int increment = 1, long startPosition = 0) : StatefulRotaryEncoderInterface(clockPin, dataPin, min, max, increment, startPosition) {
//}
//
//long StatefulLoopRotaryEncoder::getPosition() {
//	_getPoistionRaw();
//	return _pos;
//}
//
//long StatefulLoopRotaryEncoder::getPosition(int increment = 1) {
//	_increment = increment;
//	_getPoistionRaw();
//	return _pos;
//}
//
//void StatefulLoopRotaryEncoder::_getPoistionInner() : _getPoistionInner() {
//	while (_pos > _max) {
//		_pos = ((_pos - _max) + _min);
//	}
//	while (_pos < _min) {
//		_pos = (_max - (_min - _pos));
//	}
//}
//
////  END:  StatefulRotaryEncoderInterface interface
//// ========================================================
//
//
////// ========================================================
////// START: StatefulBounceRotaryEncoder interface
////
////StatefulBounceRotaryEncoder::StatefulBounceRotaryEncoder(byte clockPin, byte dataPin, long min, long max, int increment = 1, long startPosition = 0) : StatefulRotaryEncoderInterface(clockPin, dataPin, min, max, increment, startPosition) {
////}
////
////long StatefulBounceRotaryEncoder::getPosition() {
////	_getPoistionInner();
////	return _pos;
////}
////long StatefulBounceRotaryEncoder::getPosition(int increment = 1) {
////	_increment = increment;
////	_getPoistionInner();
////	return getPosition();
////}
////
////void StatefulBounceRotaryEncoder::_getPoistionInner() : _getPoistionInner() {
////	while (_pos > _max) {
////		_pos = ((_pos - _max) + _min);
////	}
////	while (_pos < _min) {
////		_pos = (_max - (_min - _pos));
////	}
////}
////
//////  END:  StatefulRotaryEncoderInterface interface
////// ========================================================
//
