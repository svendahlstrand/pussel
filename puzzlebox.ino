#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "board.h"
#include "board_view.h"

Board board;
BoardView boardView(board);

void setup() {
  board.begin(analogRead(0));
  boardView.begin();
  boardView.render();
}

void loop() {
  while (Serial.available() > 0) {
    board.makeMove(Serial.parseInt(), Serial.parseInt());
    boardView.render();
  }
}
