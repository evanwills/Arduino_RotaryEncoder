# `RotaryEncoder`

Simplifies doing common things with a rotary encoder.


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