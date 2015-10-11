#ifndef PUSSEL_LIGHTS_OUT_H
#define PUSSEL_LIGHTS_OUT_H

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
  int kNumberOfLights();

 private:
  int positionFromRowAndColum(int row, int colum);
  void togglePositionAndNeighbors(int position);
  void togglePosition(int position);

  static const int kNumberOfRowsAndColumns_ = 4;
  static const int kNumberOfLights_ = 16;
  bool state_[kNumberOfLights_];
};

#endif  // PUSSEL_LIGHTS_OUT_H
