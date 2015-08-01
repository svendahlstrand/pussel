#include <Wire.h>

#include "lights_out.h"
#include "lights_out_serial_view.h"

LightsOut lightsOut;
LightsOutSerialView lightsOutView(lightsOut);

void setup() {
  lightsOut.begin(analogRead(0));
  lightsOutView.begin();
  lightsOutView.render();
}

void loop() {
  while (Serial.available() > 0) {
    lightsOut.makeMove(Serial.parseInt(), Serial.parseInt());
    lightsOutView.render();
  }
}
