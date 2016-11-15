# `RotaryEncoder` and `StatefulRotaryEncoder`

## `RotaryEncoder`

Simplifies doing common things with a rotary encoder.

__NOTE:__ All state for this object is managed externally (except the last reading of the clock pin). It is up to the calling code to provide the current absolute position of the encoder. The object only provides the relative change in position.

__`long getPosition( long startPosition[, unsigned int increment = 1] )`__ returns the updated position of the rotary encoder.

__`long getPositionLimited(long startPosition, long min, long max[, unsigned int increment = 1])`__ returns the updated position of the rotary encoder but limits the position to within the minimum/maximum. e.g.
*	if `min` is -5 and `max` is 10 and the output position is 13. Then the position will be adjusted to 10.
*	if `min` is -5 and `max` is 10 and the output position is -12. Then the position will be adjusted to -5.
*	if `min` is -5 and `max` is 10 and the output position is 44. Then the position will be adjusted to 10.

__`long getPositionLoopAround(long startPosition, long min, long max[, unsigned int increment = 1])`__ returns the updated position of the rotary encoder but loops the position around to the other end when the minimum or maximum is reached. e.g.
*	if `min` is -5 and `max` is 10 and the output position is 13. Then the position will be adjusted to -2.<br />`((13 - 10) + -5)`
*	if `min` is -5 and `max` is 10 and the output position is -12. Then the position will be adjusted to 3.<br />`(10 - (-5 - -12))`
*	if `min` is -5 and `max` is 10 and the output position is 44. Then the position will be adjusted to -1	.<br />`((44 - 10) + -5) = 29` _(still too big so adjust again)_<br />`((29 - 10) + -5) = 14` _(still too big so adjust again)_<br />`((14 - 10) + -5) = -1` _(now within range)_

NOTE: the adjustment happens in a loop so that, regardless of the starting value, it will always end up within the min/max range

<!--
## `BtnRotaryEncoder`:

Inherits all of the above methods as well as implementing the `FlexibleButtonInterface` making it usable as a normal button. This gives it the flexibility of being able to do any of the [`FlexibleButtons`](https://github.com/evanwills/FlexibleButtons) functions

`FlexibleButtonInterface` methods:

__`isPressed()`__ returns true if the button is pressed

__`getState()`__ returns an integer value for the button's state.
-->

## `StatefulRotaryEncoder`

StatefulRotaryEncoder simplifies using a rotary encoder for single purpose things. You could even use multiple objects for the same physical encoder by calling each object under different conditions. The calling code is only privy the absolute state of the encoder. Not the relative change from one call to the next.

### interface:

#### `StatefulRotaryEncoder(clockPin, dataPin, min, max, increment, startPosition)`

*	__`byte clockPin`__ the pin the clock (or A) pin will be connected to
*	__`byte dataPin`__ the pin the data (or B) pin will be connected to
*	__`long min`__ minimum value the object can output
*	__`long max`__ maximum value the object can output
*	__`unsigned int increment = 1`__ the amount to change the output for each step made to the encoder.
*	__`long startPosition = 0`__ the initial value the encoder starts with.

#### `long getPosition([unsigned int increment])`

returns the absolute position of the encoder.

*	__`unsigned int increment`__ (optional) the amount to change the output for each step made to the encoder. Passing `increment` updates the object's internal _increment value which is what is actually used to increment the position of the encoder.


## Sub-classes

### `StatefulLimitedRotaryEncoder`

Ensures the output of `getPosition()` does not go beyond the minimum or maximum specified in the constructor. See getPositionLimited() above, for how it works.

### `StatefulLoopRotaryEncoder`

Ensures the output of `getPosition()` goes beyond the maximum (or minimum) it's looped around to the begining (or end). See getPositionLoopAround() above, for how it works.

