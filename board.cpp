#include "board.h"

Board::Board(int size) : size_(size) {
  state_ = new bool[size_ * size_];

  for (int i = 0; i < size_ * size_; i++) {
    state_[i] = true;
  }
}

void Board::begin(int seed = 0) {
  srand(seed);

  shuffle();
}

void Board::shuffle() {
  int numberOfMoves = rand() % ((int) size_ * size_ / 2) + 1;

  for (int i = 0; i < numberOfMoves; i++) {
    int randomPosition = rand() % (size_ * size_);

    togglePositionAndNeighbors(randomPosition);
  }
}

void Board::makeMove(int row, int column) {
  int position = row * size_ + column;

  togglePositionAndNeighbors(position);
}

bool Board::isLit(int row, int column) {
  int position = row * size_ + column;

  return state_[position];
}

bool Board::isAllLit() {
  for (int i = 0; i < size_ * size_; i++) {
    if (state_[i] == false) return false;
  }

  return true;
}

void Board::togglePositionAndNeighbors(int position) {
  togglePosition(position);
  togglePosition(position - size_);
  togglePosition(position + size_);

  if (position % 4 != 0) togglePosition(position - 1);
  if ((position + 1) % 4 != 0) togglePosition(position + 1);
}

void Board::togglePosition(int position) {
  if (position >= 0 && position < size_ * size_) {
    state_[position] = !state_[position];
  }
}

int Board::size() {
  return size_;
}

