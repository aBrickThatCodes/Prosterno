#ifndef PROSTERNO_PIECE_WHITEPIECE_H_
#define PROSTERNO_PIECE_WHITEPIECE_H_

#include "Piece.hpp"

class WhitePiece : public Piece {
public:
    explicit WhitePiece(std::pair<int, int>& position) : Piece(position) {}

    std::vector<std::pair<int, int>> get_moves() noexcept override;

    ~WhitePiece() override = default;
};

#endif// PROSTERNO_PIECE_WHITEPIECE_H_
