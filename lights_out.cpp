#include "lights_out.h"

LightsOut::LightsOut() {
  for (int i = 0; i < kNumberOfLights_; i++) {
    state_[i] = true;
  }
}

void LightsOut::begin(int seed = 0) {
  srand(seed);

  shuffle();
}

void LightsOut::shuffle() {
  int numberOfMoves = rand() % ((int) kNumberOfLights_ / 2) + 1;

  for (int i = 0; i < numberOfMoves; i++) {
    int randomPosition = rand() % kNumberOfLights_;

    togglePositionAndNeighbors(randomPosition);
  }
}

void LightsOut::makeMove(int row, int column) {
  togglePositionAndNeighbors(positionFromRowAndColum(row, column));
}

bool LightsOut::isLit(int row, int column) {
  return state_[positionFromRowAndColum(row, column)];
}

bool LightsOut::isAllLit() {
  for (int i = 0; i < kNumberOfLights_; i++) {
    if (state_[i] == false) return false;
  }

  return true;
}

int LightsOut::kNumberOfRowsAndColumns() {
  return kNumberOfRowsAndColumns_;
}

int LightsOut::positionFromRowAndColum(int row, int column) {
  return row * kNumberOfRowsAndColumns_ + column;
}

void LightsOut::togglePositionAndNeighbors(int position) {
  togglePosition(position);
  togglePosition(position - kNumberOfRowsAndColumns_);
  togglePosition(position + kNumberOfRowsAndColumns_);

  if (position % 4 != 0) togglePosition(position - 1);
  if ((position + 1) % 4 != 0) togglePosition(position + 1);
}

void LightsOut::togglePosition(int position) {
  if (position >= 0 && position < kNumberOfLights_) {
    state_[position] = !state_[position];
  }
}
