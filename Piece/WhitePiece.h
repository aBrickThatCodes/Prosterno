#ifndef PROSTERNO_PIECE_WHITEPIECE_H
#define PROSTERNO_PIECE_WHITEPIECE_H

#include "Piece.h"

class WhitePiece : public Piece {
 public:
  explicit WhitePiece(std::pair<int, int>& position) : Piece(position) {}

  std::vector<std::pair<int, int>> GetMoves() noexcept override;

  ~WhitePiece() override = default;
};

#endif// PROSTERNO_PIECE_WHITEPIECE_H
