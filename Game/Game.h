#ifndef PROSTERNO_GAME_GAME_H
#define PROSTERNO_GAME_GAME_H

#include "../Board/Board.h"

#include <utility>
#include <vector>

class Game {
 public:
  enum Player { kNone,
                kWhite,
                kBlack };

 private:
  Board board_;
  Player current_player_ = kWhite;

  std::pair<int, int> get_move_from() noexcept;
  static std::pair<int, int>
  get_move_to(std::pair<int, int> from,
              const std::vector<std::pair<int, int>>& possible) noexcept;

 public:
  Game() noexcept : board_() {}

  [[nodiscard]] Player get_winner() const noexcept;
  void print_board() noexcept;
  void loop() noexcept;
};

#endif// PROSTERNO_GAME_GAME_H
