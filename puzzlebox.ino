#include <Wire.h>

#include "lights_out.h"
#include "lights_out_trellis_view.h"

LightsOut lightsOut;
LightsOutTrellisView lightsOutView(lightsOut);

void setup() {
  lightsOut.begin(analogRead(0));
  lightsOutView.begin();
  lightsOutView.renderWithDelay(60);
}

void loop() {
  if (lightsOutView.shouldHandleButtonActivity()) {
    for (int row = 0; row < lightsOut.kNumberOfRowsAndColumns(); row++) {
      for (int column = 0; column < lightsOut.kNumberOfRowsAndColumns(); column++) {
        if (lightsOutView.wasButtonJustPressed(row, column)) {
          lightsOut.makeMove(row, column);
        }
      }
    }

    if (lightsOut.isAllLit()) {
      lightsOutView.renderWinSequence();
      lightsOut.shuffle();
      lightsOutView.renderWithDelay(60);
    }
    else {
      lightsOutView.render();
    }
  }
}

