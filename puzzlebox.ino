#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "lights_out.h"
#include "board_view.h"

LightsOut lightsOut;
BoardView boardView(lightsOut);

void setup() {
  lightsOut.begin(analogRead(0));
  boardView.begin();
  boardView.render();
}

void loop() {
  while (Serial.available() > 0) {
    lightsOut.makeMove(Serial.parseInt(), Serial.parseInt());
    boardView.render();
  }
}
