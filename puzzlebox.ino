#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "board.h"
#include "board_view.h"

Board board;
BoardView boardView(board);

int userMoveRow = 0;
int userMoveColumn= 0;

void setup() {
  board.begin(analogRead(0));
  boardView.begin();
  boardView.render();
}

void loop() {
  while (Serial.available() > 0) {
    userMoveRow = Serial.parseInt();
    userMoveColumn = Serial.parseInt();

    board.makeMove(userMoveRow, userMoveColumn);
    boardView.render();
  }
}
