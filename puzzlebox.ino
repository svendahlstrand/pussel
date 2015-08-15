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
  lightsOutView.update();

  if (lightsOutView.oneOrMoreInPressedButtonsBuffer()) {
    for (int button = lightsOutView.popPressedButtonsBuffer(); button >= 0; button = lightsOutView.popPressedButtonsBuffer()) {
      int row = (int) button / lightsOut.kNumberOfRowsAndColumns();
      int column = button % lightsOut.kNumberOfRowsAndColumns();

      lightsOut.makeMove(row, column);
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

