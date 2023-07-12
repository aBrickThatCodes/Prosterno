#ifndef PROSTERNO_GAME_GAME_H_
#define PROSTERNO_GAME_GAME_H_

#include "../Board/Board.h"

#include <utility>
#include <vector>

class Game {
public:
  enum Player { kNone, kWhite, kBlack };
private:
  Board board_;
  Player current_player_;

  std::pair<int, int> GetMoveFrom() noexcept;
  static std::pair<int, int> GetMoveTo(std::pair<int, int> from,
                                       const std::vector<std::pair<int, int>>& possible) noexcept;
public:
  Game() noexcept: board_(), current_player_(Player::kWhite) {}
  [[nodiscard]] Player GetWinner() const noexcept;
  void PrintBoard() noexcept;
  void Loop() noexcept;
};

#endif //PROSTERNO_GAME_GAME_H_
