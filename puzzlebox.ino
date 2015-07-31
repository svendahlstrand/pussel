#include <Wire.h>

#include "Adafruit_Trellis.h"
#include "board.h"

const int kBoardSize = 4;
Board* board;
int user_move_row = 0;
int user_move_column = 0;

void setup() {
  Serial.begin(9600);

  board = new Board(kBoardSize, analogRead(0));
  render_board_view();
}

void loop() {
  while (Serial.available() > 0) {
    user_move_row = Serial.parseInt();
    user_move_column = Serial.parseInt();

    board->MakeMove(user_move_row, user_move_column);
    render_board_view();
  }
}

void render_board_view() {
  for (int row = 0; row < board->size(); row++) {
    for (int column = 0; column < board->size(); column++) {
      Serial.print(board->IsLit(row, column) ? "1" : "0");
      Serial.print(" ");
    }

    Serial.println("");
  }

  Serial.println("");
}
