#include "Board.h"

#include "../Piece/WhitePiece.h"
#include "../Piece/BlackPiece.h"

Board::Board() noexcept: white_pieces_(8), black_pieces_(8) {
  for (int i = 0; i < 8; ++i) {
    std::pair<int, int> white_pos{i + 1, 1 + (i + 1) % 2};
    GetPiece(white_pos) = std::unique_ptr<Piece>(new WhitePiece(white_pos));
    std::pair<int, int> black_pos{i + 1, board_.size() - (i + 1) % 2};
    GetPiece(black_pos) = std::unique_ptr<Piece>(new BlackPiece(black_pos));
  }
}

std::unique_ptr<Piece> &Board::GetPiece(std::pair<int, int> at) noexcept {
  return board_.at(at.first - 1).at(at.second - 1);
}

bool Board::MovePiece(std::pair<int, int> from, std::pair<int, int> to) noexcept {
  auto &u1 = GetPiece(from);

  if (to.first - 1 < 0 || to.first - 1 >= board_.size() || to.second - 1 < 0 || to.second - 1 >= board_.size()) {
    if (dynamic_cast<WhitePiece *>(u1.get()) != nullptr)
      --white_pieces_;
    else
      --black_pieces_;
    u1.reset();
    return false;
  }

  auto &u2 = GetPiece(to);
  if (u2 != nullptr) {
    if (dynamic_cast<WhitePiece *>(u1.get()) != nullptr)
      --white_pieces_;
    else
      --black_pieces_;

    u1.reset();
    return false;
  }

  u2.swap(u1);
  u2->set_position(to);
  return true;
}

void Board::MakeMove(std::pair<int, int> from, std::pair<int, int> to) noexcept {
  if (!MovePiece(from, to))
    return;

  if (to.first - 1 != 0) {
    std::pair<int, int> over = {to.first - 1, to.second};
    if (GetPiece(over) != nullptr)
      MakeMove(over, {over.first - 2, over.second});
  }

  if (to.first < board_.size() - 1) {
    std::pair<int, int> under = {to.first + 1, to.second};
    if (GetPiece(under) != nullptr)
      MakeMove(under, {under.first + 2, under.second});
  }

  if (to.second < board_.size() - 1) {
    std::pair<int, int> front = {to.first, to.second + 1};
    if (GetPiece(front) != nullptr)
      MakeMove(front, {front.first, front.second + 2});
  }

  if (to.second - 1 > 0) {
    std::pair<int, int> back = {to.first, to.second - 1};
    if (GetPiece(back) != nullptr)
      MakeMove(back, {back.first, back.second - 2});
  }
}
