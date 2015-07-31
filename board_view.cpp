#include "board_view.h"

BoardView::BoardView(Board* board) {
  board_ = board;
}

void BoardView::Render() {
  for (int row = 0; row < board_->size(); row++) {
    for (int column = 0; column < board_->size(); column++) {
      Serial.print(board_->IsLit(row, column) ? "1" : "0");
      Serial.print(" ");
    }

    Serial.println("");
  }

  Serial.println("");
}
