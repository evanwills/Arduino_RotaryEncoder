# `RotaryEncode` & `BtnRotaryEncoder`

These two classes seek to make using rotary encoders easier

`BtnRotaryEncoder` acts as a [decorator](https://en.wikipedia.org/wiki/Decorator_pattern) for [`FlexibleButtons`](https://github.com/evanwills/FlexibleButtons)

## `RotaryEncoder`:

__`getPosition()`__ returns the current position of the encoder. If called with tempIncrement passed the output is adjusted by the tempIncrment value rather increment value set within the object

__`setPosition( long newPosition )`__ allows you to preset the position of the encoder before user moves it.

__`getIncrement()`__ returns the increment value the object is currently using

__`setIncrement( unsigned int newIncrement )`__ allows you to set the increment value the object uses for modifying the position of the encoder.


## `BtnRotaryEncoder`:

Inherits all of the above methods as well as implementing the `FlexibleButtonInterface` making it usable as a normal button. This gives it the flexibility of being able to do any of the [`FlexibleButtons`](https://github.com/evanwills/FlexibleButtons) functions

`FlexibleButtonInterface` methods:

__`isPressed()`__ returns true if the button is pressed

__`getState()`__ returns an integer value for the button's state.