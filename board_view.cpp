#include "board_view.h"

BoardView::BoardView(LightsOut& lightsOut) : lightsOut_(lightsOut) {}

void BoardView::begin() {
  Serial.begin(9600);
}

void BoardView::render() {
  for (int row = 0; row < lightsOut_.kNumberOfRowsAndColumns(); row++) {
    for (int column = 0; column < lightsOut_.kNumberOfRowsAndColumns(); column++) {
      Serial.print(lightsOut_.isLit(row, column) ? "1" : "0");
      Serial.print(" ");
    }

    Serial.println("");
  }

  Serial.println("");
}
