#include "board.h"

Board::Board(int size) {
  size_ = size;

  state_ = new int [size_ * size_];

  for (int i = 0; i < size_ * size_; i++) {
    state_[i] = 1;
  }
}

void Board::Begin(int seed = 0) {
  srand(seed);

  Shuffle();
}

void Board::Shuffle() {
  int number_of_moves = rand() % ((int) size_ * size_ / 2) + 1;

  for (int i = 0; i < number_of_moves; i++) {
    int random_position = rand() % (size_ * size_);

    TogglePositionAndNeighbors(random_position);
  }
}

void Board::MakeMove(int row, int column) {
  int position = row * size_ + column;

  TogglePositionAndNeighbors(position);
}

bool Board::IsLit(int row, int column) {
  int position = row * size_ + column;

  return state_[position] == 1;
}

bool Board::IsAllLit() {
  for (int i = 0; i < size_ * size_; i++) {
    if (state_[i] == 0) return false;
  }

  return true;
}

void Board::TogglePositionAndNeighbors(int position) {
  TogglePosition(position);
  TogglePosition(position - size_);
  TogglePosition(position + size_);

  if (position % 4 != 0) TogglePosition(position - 1);
  if ((position + 1) % 4 != 0) TogglePosition(position + 1);
}

void Board::TogglePosition(int position) {
  if (position >= 0 && position < size_ * size_) {
    state_[position] = state_[position] == 1 ? 0 : 1;
  }
}

int Board::size() {
  return size_;
}

