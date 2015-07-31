#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "board.h"
#include "board_view.h"

const int kBoardSize = 4;

Board board(kBoardSize);
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
