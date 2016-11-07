/**
 * RotaryEncoder.h - simple library for using a rotary encoder.
 * It alows you to get the current state of the encoder plus preset
 * the state (if you want to use the same encoder hardware for
 * multiple variables)
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */


#ifndef RotaryEncoder_h
#define RotaryEncoder_h


#include <Arduino.h>
#include <stdlib.h>
#include <SimpleButton.h>


//// Interface for rotary encoder.
//class IRotaryEncoder {
//
//	public:
//		virtual long getPosition( bool doRead = true );
//		virtual void setPosition( long newPosition );
//};


class RotaryEncoder {

	public:
		RotaryEncoder( byte clockPin , byte dataPin );

		long getPosition();
		long getPosition(unsigned int tempIncrement);
		void setPosition( long newPosition );
		unsigned int getIncrement();
		void setIncrement( unsigned int newIncrement );


	protected:
		byte _clkPin;
		byte _dtPin;
		int _clkValue;
		int _dtValue;
		long _position;
		int _previousClkValue;
		unsigned int _increment = 1;
};

// This BtnRotaryEncoder inherits from both rotaryEncoder and the
// interface for TimedButton, alowing it to be passed around as a
// button in its own right.
//
// BtnRotaryEncoder can be thought of as a decorator for TimedButtons

class BtnRotaryEncoder : public RotaryEncoder , public FlexibleButtonInterface {
//class BtnRotaryEncoder : public RotaryEncoder , public SimpleButton {

	public:
		BtnRotaryEncoder( byte clockPin , byte dataPin , FlexibleButtonInterface& button );
		// these methods are required by the FlexibleButtonInterface interface
		bool isPressed();
		int getState();

	protected:
		FlexibleButtonInterface& _btn;

};

#endif
