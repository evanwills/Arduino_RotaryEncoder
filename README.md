# `RotaryEncode` & `BtnRotaryEncoder`

These two classes seek to make using rotary encoders easier

`BtnRotaryEncoder` acts as a [decorator](https://en.wikipedia.org/wiki/Decorator_pattern) for [`FlexibleButtons`](https://github.com/evanwills/FlexibleButtons)

## `RotaryEncoder`:

__`long getPosition( [unsigned int tempIncrement] )`__ returns the current position of the encoder. If called with tempIncrement passed the output is adjusted by the tempIncrment value rather increment value set within the object

__`void setPosition( long newPosition )`__ allows you to preset the position of the encoder before user moves it.

__`long getPositionLimited( long min, long max [, unsigned int tempIncrement] )`__ returns the current (cumulative) position of the rotary encoder but limits the position to within the minimum/maximum

__`long getPositionLoopAround( long min, long max [, unsigned int tempIncrement] )`__ returns the current (cumulative) position of the rotary encoder but loops the position around to the other end when the minimum or maximum is reached

e.g.
*	if min is -5 and max is 10 and the position is 13. The position will be adjusted to -2.<br />`(-5 + (13 - 10))`
*	if min is -5 and max is 10 and position is -12. Then the position is adjusted to 3.<br />`(10 - -(-12 - -5))`


__`unsigned int getIncrement()`__ returns the increment value the object is currently using

__`void setIncrement( unsigned int newIncrement )`__ allows you to set the increment value the object uses for modifying the position of the encoder.

__`void setPosition( long newPosition )`__ allows you to preset the position. (Useful if you are using the same encoder for multiple variables.)

## `BtnRotaryEncoder`:

Inherits all of the above methods as well as implementing the `FlexibleButtonInterface` making it usable as a normal button. This gives it the flexibility of being able to do any of the [`FlexibleButtons`](https://github.com/evanwills/FlexibleButtons) functions

`FlexibleButtonInterface` methods:

__`isPressed()`__ returns true if the button is pressed

__`getState()`__ returns an integer value for the button's state.