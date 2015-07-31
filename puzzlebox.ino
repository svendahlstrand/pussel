#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "board.h"
#include "board_view.h"

const int kBoardSize = 4;

Board board(kBoardSize);
BoardView board_view;

int user_move_row = 0;
int user_move_column = 0;

void setup() {
  board.Begin(analogRead(0));
  board_view.Begin(&board);
  board_view.Render();
}

void loop() {
  while (Serial.available() > 0) {
    user_move_row = Serial.parseInt();
    user_move_column = Serial.parseInt();

    board.MakeMove(user_move_row, user_move_column);
    board_view.Render();
  }
}
