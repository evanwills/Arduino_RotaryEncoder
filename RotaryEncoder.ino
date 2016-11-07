#include "RotaryEncoder.h"

RotaryEncoder basicEncoder(30,32);

SimpleButton btn(38);
BtnRotaryEncoder btnEncoder(34,36, btn);

void setup() {
	btn.makePinModePullup();
}

void loop() {
	long pos = btnEncoder.getPosition();
}