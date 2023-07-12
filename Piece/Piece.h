#ifndef PROSTERNO_PIECE_PIECE_H_
#define PROSTERNO_PIECE_PIECE_H_

#include <utility>
#include <vector>

class Piece {
 protected:
  std::pair<int, int> position_;
 public:
  explicit Piece(std::pair<int, int> position) noexcept: position_(std::move(position)) {}
  Piece(Piece& p) noexcept = default;
  void set_position(std::pair<int, int>& position) noexcept {
    position_ = position;
  }
  std::pair<int, int> position() { return position_; }
  virtual std::vector<std::pair<int, int>> GetMoves() noexcept = 0;
  virtual ~Piece() noexcept = default;

  friend class Board;
};

#endif //PROSTERNO_PIECE_PIECE_H_
