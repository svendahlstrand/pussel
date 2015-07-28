#include "board.h"

const int kBoardSize = 4;
Board board(kBoardSize);

void setup() {
  board.MakeMove(0, 3);
  board.MakeMove(3, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
