#ifndef PUZZLEBOX_BOARD_VIEW_H
#define PUZZLEBOX_BOARD_VIEW_H

#include <arduino.h>

#include "lights_out.h"

class BoardView {
 public:
  explicit BoardView(LightsOut& lightsOut);

  void begin();
  void render();
 private:
  LightsOut& lightsOut_;
};

#endif  // PUZZLEBOX_BOARD_VIEW_H
