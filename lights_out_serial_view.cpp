#include "lights_out_serial_view.h"

LightsOutSerialView::LightsOutSerialView(LightsOut& lightsOut) : lightsOut_(lightsOut) {}

void LightsOutSerialView::begin() {
  Serial.begin(9600);
}

void LightsOutSerialView::render() {
  for (int row = 0; row < lightsOut_.kNumberOfRowsAndColumns(); row++) {
    for (int column = 0; column < lightsOut_.kNumberOfRowsAndColumns(); column++) {
      Serial.print(lightsOut_.isLit(row, column) ? "1" : "0");
      Serial.print(" ");
    }

    Serial.println("");
  }

  Serial.println("");
}
