#ifndef PROSTERNO_PIECE_BLACKPIECE_H_
#define PROSTERNO_PIECE_BLACKPIECE_H_

#include "Piece.hpp"

class BlackPiece : public Piece {
public:
    explicit BlackPiece(std::pair<int, int>& position) : Piece(position) {}

    std::vector<std::pair<int, int>> get_moves() noexcept override;

    ~BlackPiece() override = default;
};

#endif// PROSTERNO_PIECE_BLACKPIECE_H_
