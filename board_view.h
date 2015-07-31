#ifndef PUZZLEBOX_BOARD_VIEW_H
#define PUZZLEBOX_BOARD_VIEW_H

#include <arduino.h>

#include "board.h"

class BoardView {
 public:
  explicit BoardView(Board* board);

  void Render();
 private:
  Board* board_;
};

#endif  // PUZZLEBOX_BOARD_VIEW_H
