#ifndef PUZZLEBOX_LIGHTS_OUT_H
#define PUZZLEBOX_LIGHTS_OUT_H

#include <stdlib.h>

class LightsOut {
 public:
  explicit LightsOut();

  void begin(int seed);
  void shuffle();
  void makeMove(int row, int column);
  bool isLit(int row, int column);
  bool isAllLit();
  int kNumberOfRowsAndColumns();

 private:
  void togglePositionAndNeighbors(int position);
  void togglePosition(int position);

  static const int kNumberOfRowsAndColumns_ = 4;
  static const int kNumberOfLights_ = 16;
  bool state_[kNumberOfLights_];
};

#endif  // PUZZLEBOX_LIGHTS_OUT_H
