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
#include <TimedButton.h>


 // Interface for rotary encoder.
class IRotaryEncoder {

	public:
		virtual long getPosition( bool doRead = true );
		virtual void setPosition( long newPosition );
}


class RotaryEncoder : public IRotaryEncoder {

	public:
		RotaryEncoder( byte clockPin , byte dataPin );

		long getPosition( bool read = true );
		void setPosition( long newPosition );


	protected:
		byte clkPin;
		byte dtPin;
		int clk_value;
		int dt_value;
		long position;
		int previous_clk_value;
		int increment = 1;
}

// This BtnRotaryEncoder inherits from both rotaryEncoder and the
// interface for TimedButton, alowing it to be passed around as a
// button in its own right.
//
// BtnRotaryEncoder can be thought of as a decorator for TimedButtons

class BtnRotaryEncoder : public RotaryEncoder , public ITimedButton {

	public:
		BtnRotaryEncoder( int clockPin , int dataPin , ITimedButton button );
		// these methods are required by the ITimedButton interface
		bool readButton();
		int pressed();

	protected:
		ITimedButton btn;

}

#endif