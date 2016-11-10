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
		 * @param unsigned int increment sets the increment by
		 *		  which the position of the encoder is stepped with
		 *		  each move
		 *		  By default the increment value is allows the
		 *		  increment to be overriden on a per call basis
		 */
		long getPosition(long startPosition, unsigned int tempIncrement = 1);

		/**
		 * returns the current (cumulative) position of the rotary
		 * encoder but limits the position to within the minimum/maximum
		 *
		 * @param long min the minimum value the output position can be
		 * @param long max the maximum value the output position can be
		 *
		 * @param unsigned int increment sets the increment by
		 *		  which the position of the encoder is stepped with
		 *		  each move
		 */
		long getPositionLimited(long startPosition, long min, long max, unsigned int increment = 1);

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
		 * @param unsigned int increment sets the increment by
		 *		  which the position of the encoder is stepped with
		 *		  each move
		 */
		long getPositionLoopAround(long startPosition, long min, long max, unsigned int increment = 1);

	protected:
		byte _clkPin;
		byte _dtPin;
		int _clkValue;
		int _dtValue;
		int _previousClkValue;
};

/**
 * This is removed in favour of just using the button separately.
 * Later it might be worth making this a decorator for both
 * RotaryEncoder and FlexibleButton but for now I'm going for
 * composability over inheritance

// This BtnRotaryEncoder inherits from both rotaryEncoder and the
// interface for TimedButton, alowing it to be passed around as a
// button in its own right.
//
// BtnRotaryEncoder can be thought of as a decorator for TimedButtons

class BtnRotaryEncoder : public RotaryEncoder , public FlexibleButtonInterface {
//class BtnRotaryEncoder : public RotaryEncoder , public SimpleButton {

	public:
		BtnRotaryEncoder( RotaryEncoder encoder , FlexibleButtonInterface& button );

		// these methods are required by the RotaryEncoder interface
		long getPosition(long startPosition, unsigned int tempIncrement = 1);
		long getPositionLimited(long startPosition, long min, long max, unsigned int increment = 1);
		long getPositionLoopAround(long startPosition, long min, long max, unsigned int increment = 1);


		// these methods are required by the FlexibleButtonInterface interface
		bool isPressed();
		int getState();

	protected:
		RotaryEncoder _encoder
		FlexibleButtonInterface& _btn;

};
*/

#endif
