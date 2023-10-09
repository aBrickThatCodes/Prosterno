#include "Board.hpp"

#include "../Piece/BlackPiece.hpp"
#include "../Piece/WhitePiece.hpp"

Board::Board() noexcept : black_pieces_(8), white_pieces_(8) {
    for (int i = 0; i < 8; ++i) {
        std::pair<int, int> white_pos{i + 1, 1 + (i + 1) % 2};
        get_piece(white_pos) = std::unique_ptr<Piece>(new WhitePiece(white_pos));
        std::pair<int, int> black_pos{i + 1, board_.size() - (i + 1) % 2};
        get_piece(black_pos) = std::unique_ptr<Piece>(new BlackPiece(black_pos));
    }
}

std::unique_ptr<Piece>& Board::get_piece(std::pair<int, int> at) noexcept {
    return board_.at(at.first - 1).at(at.second - 1);
}

bool Board::move_piece(std::pair<int, int> from,
                       std::pair<int, int> to) noexcept {
    auto& u1 = get_piece(from);

    if (to.first - 1 < 0 || to.first - 1 >= board_.size() || to.second - 1 < 0 || to.second - 1 >= board_.size()) {
        if (dynamic_cast<WhitePiece*>(u1.get()) != nullptr) {
            --white_pieces_;
        } else {
            --black_pieces_;
        }
        u1.reset();
        return false;
    }

    auto& u2 = get_piece(to);
    if (u2 != nullptr) {
        if (dynamic_cast<WhitePiece*>(u1.get()) != nullptr) {
            --white_pieces_;
        } else {
            --black_pieces_;
        }
        u1.reset();
        return false;
    }

    u2.swap(u1);
    u2->set_position(to);
    return true;
}

void Board::make_move(std::pair<int, int> from,
                      std::pair<int, int> to) noexcept {
    if (!move_piece(from, to)) {
        return;
    }

    if (to.first - 1 != 0) {
        std::pair<int, int> over = {to.first - 1, to.second};
        if (get_piece(over) != nullptr) {
            make_move(over, {over.first - 2, over.second});
        }
    }

    if (to.first < board_.size() - 1) {
        std::pair<int, int> under = {to.first + 1, to.second};
        if (get_piece(under) != nullptr) {
            make_move(under, {under.first + 2, under.second});
        }
    }

    if (to.second < board_.size() - 1) {
        std::pair<int, int> front = {to.first, to.second + 1};
        if (get_piece(front) != nullptr) {
            make_move(front, {front.first, front.second + 2});
        }
    }

    if (to.second - 1 > 0) {
        std::pair<int, int> back = {to.first, to.second - 1};
        if (get_piece(back) != nullptr) {
            make_move(back, {back.first, back.second - 2});
        }
    }
}
