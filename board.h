#ifndef PUZZLEBOX_BOARD_H
#define PUZZLEBOX_BOARD_H

#include <stdlib.h>

class Board {
 public:
  explicit Board();

  void begin(int seed);
  void shuffle();
  void makeMove(int row, int column);
  bool isLit(int row, int column);
  bool isAllLit();
  int kSize();

 private:
  void togglePositionAndNeighbors(int position);
  void togglePosition(int position);

  static const int kSize_ = 4;
  bool state_[kSize_ * kSize_];
};

#endif  // PUZZLEBOX_BOARD_H
