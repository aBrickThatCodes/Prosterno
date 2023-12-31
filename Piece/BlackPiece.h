#ifndef PROSTERNO_PIECE_BLACKPIECE_H
#define PROSTERNO_PIECE_BLACKPIECE_H

#include "Piece.h"

class BlackPiece : public Piece {
 public:
  explicit BlackPiece(std::pair<int, int>& position) : Piece(position) {}

  std::vector<std::pair<int, int>> GetMoves() noexcept override;

  ~BlackPiece() override = default;
};

#endif// PROSTERNO_PIECE_BLACKPIECE_H
