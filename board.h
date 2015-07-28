#ifndef PUZZLEBOX_BOARD_H
#define PUZZLEBOX_BOARD_H

#include "arduino.h"

class Board {
 public:
  explicit Board(int size);

  void Shuffle();
  void MakeMove(int row, int column);
  bool IsLit(int row, int column);
  bool isAllLit();

  int size();
  
 private:
  void TogglePositionAndNeighbors(int position);
  void TogglePosition(int position);

  int* state_;
  int size_;
};

#endif  // PUZZLEBOX_BOARD_H
