/**
 * RotaryEncoder.h - simple library for using a rotary encoder.
 * It alows you to get the current state of the encoder plus preset
 * the state (if you want to use the same encoder hardware for
 * multiple variables)
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */


#ifndef StatefulRotaryEncoder_h
#define StatefulRotaryEncoder_h


#include <Arduino.h>
#include <stdlib.h>


/**
 * StatefulRotaryEncoder simplifies using a rotary encoder for single
 * purpose things. You could even use multiple objects for the same
 * physical encoder by calling each object under different conditions.
*/

class StatefulRotaryEncoderInterface {
	public:
		StatefulRotaryEncoderInterface(byte clockPin, byte dataPin, long min, long max, unsigned int increment = 1, long startPosition = 0);
		virtual long getPosition();
		virtual long getPosition(unsigned int increment);

	protected:
		byte _clkPin;
		byte _dtPin;
		long _min = 0;
		long _max = 0;
		long _pos = 0;
		unsigned int increment;
		void _getPoistionRaw();
};



class StatefulLimitedRotaryEncoder : StatefulRotaryEncoderInterface {
	public:
		long getPosition();
		long getPosition(unsigned int increment);
};



class StatefulLoopRotaryEncoder : StatefulRotaryEncoderInterface {
	public:
		long getPosition();
		long getPosition(unsigned int increment);
};



class StatefulBounceRotaryEncoder : StatefulRotaryEncoderInterface {
	public:
		long getPosition();
		long getPosition(unsigned int increment);
};




#endif
