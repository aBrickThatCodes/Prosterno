#include "WhitePiece.h"

std::vector<std::pair<int, int>> WhitePiece::GetMoves() noexcept {
  std::vector<std::pair<int, int>> v;

  if (position_.second == 8)
    return v;

  if (position_.first - 1 > 0)
    v.emplace_back(position_.first - 1, position_.second + 1);

  if (position_.first < 8)
    v.emplace_back(position_.first + 1, position_.second + 1);

  return v;
}
