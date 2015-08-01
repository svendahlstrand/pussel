#ifndef PUZZLEBOX_BOARD_H
#define PUZZLEBOX_BOARD_H

#include <stdlib.h>

class Board {
 public:
  explicit Board(int size);

  void begin(int seed);
  void shuffle();
  void makeMove(int row, int column);
  bool isLit(int row, int column);
  bool isAllLit();

  int size();

 private:
  void togglePositionAndNeighbors(int position);
  void togglePosition(int position);

  bool* state_;
  int size_;
};

#endif  // PUZZLEBOX_BOARD_H
