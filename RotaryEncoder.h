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
#include <FlexibleButtons.h>


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

		/**
		 * returns the current (cumulative) position of the rotary
		 * encoder
		 *
		 * @param unsigned int tempIncrement sets the increment by
		 *		  which the position of the encoder is stepped with
		 *		  each move
		 *		  By default the increment value is allows the
		 *		  increment to be overriden on a per call basis
		 */
		long getPosition();
		long getPosition(unsigned int tempIncrement);

		/**
		 * returns the current (cumulative) position of the rotary
		 * encoder but limits the position to within the minimum/maximum
		 *
		 * @param long min the minimum value the output position can be
		 * @param long max the maximum value the output position can be
		 *
		 * @param unsigned int tempIncrement sets the increment by
		 *		  which the position of the encoder is stepped with
		 *		  each move
		 */
		long getPositionLimited( long min, long max);
		long getPositionLimited( long min, long max, unsigned int tempIncrement );

		/**
		 * returns the current (cumulative) position of the rotary
		 * encoder but loops the position around to the other end
		 * when the minimum or maximum is reached
		 *
		 * e.g. if the min is -5 and the max is 10 and the position
		 *		is 13. The position will be adjusted to -2
		 *
		 * @param long min the minimum value the output position can be
		 * @param long max the maximum value the output position can be
		 *
		 * @param unsigned int tempIncrement sets the increment by
		 *		  which the position of the encoder is stepped with
		 *		  each move
		 */
		long getPositionLoopAround( long min, long max);
		long getPositionLoopAround( long min, long max, unsigned int tempIncrement );

		/**
		 * presets the position of the encoder
		 *
		 * Useful if you're using one encoder for multiple values.
		 */
		void setPosition( long newPosition );

		/**
		 * returns the default increment used by the encoder
		 */
		unsigned int getIncrement();

		/**
		 * Allows you to change the default increment used by the
		 * encoder
		 */
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
