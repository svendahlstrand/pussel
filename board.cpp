#include "board.h"

Board::Board() {
  for (int i = 0; i < kSize_ * kSize_; i++) {
    state_[i] = true;
  }
}

void Board::begin(int seed = 0) {
  srand(seed);

  shuffle();
}

void Board::shuffle() {
  int numberOfMoves = rand() % ((int) kSize_ * kSize_ / 2) + 1;

  for (int i = 0; i < numberOfMoves; i++) {
    int randomPosition = rand() % (kSize_ * kSize_);

    togglePositionAndNeighbors(randomPosition);
  }
}

void Board::makeMove(int row, int column) {
  int position = row * kSize_ + column;

  togglePositionAndNeighbors(position);
}

bool Board::isLit(int row, int column) {
  int position = row * kSize_ + column;

  return state_[position];
}

bool Board::isAllLit() {
  for (int i = 0; i < kSize_ * kSize_; i++) {
    if (state_[i] == false) return false;
  }

  return true;
}

void Board::togglePositionAndNeighbors(int position) {
  togglePosition(position);
  togglePosition(position - kSize_);
  togglePosition(position + kSize_);

  if (position % 4 != 0) togglePosition(position - 1);
  if ((position + 1) % 4 != 0) togglePosition(position + 1);
}

void Board::togglePosition(int position) {
  if (position >= 0 && position < kSize_ * kSize_) {
    state_[position] = !state_[position];
  }
}

int Board::kSize() {
  return kSize_;
}

