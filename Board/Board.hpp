#ifndef PROSTERNO_BOARD_BOARD_H_
#define PROSTERNO_BOARD_BOARD_H_

#include "../Piece/Piece.hpp"

#include <array>
#include <memory>
#include <utility>
#include <vector>

class Board {
private:
    int black_pieces_;
    int white_pieces_;
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board_;

public:
    Board() noexcept;
    bool move_piece(std::pair<int, int> from, std::pair<int, int> to) noexcept;
    std::unique_ptr<Piece>& get_piece(std::pair<int, int> at) noexcept;
    void make_move(std::pair<int, int> from, std::pair<int, int> to) noexcept;

    friend class Game;
};

#endif// PROSTERNO_BOARD_BOARD_H_
