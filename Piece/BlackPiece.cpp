#include "BlackPiece.h"

std::vector<std::pair<int, int>> BlackPiece::get_moves() noexcept {
    std::vector<std::pair<int, int>> v;

    if (position.second == 0) {
        return v;
    }

    if (position.first - 1 > 0) {
        v.emplace_back(position.first - 1, position.second - 1);
    }

    if (position.first < 8) {
        v.emplace_back(position.first + 1, position.second - 1);
    }

    return v;
}
