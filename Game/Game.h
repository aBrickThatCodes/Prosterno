#ifndef PROSTERNO_GAME_GAME_H_
#define PROSTERNO_GAME_GAME_H_

#include "../Board/Board.h"

#include <utility>
#include <vector>

class Game {
public:
    enum Player { None,
                  White,
                  Black };

private:
    Board board_;
    Player current_player_;

    std::pair<int, int> get_move_from() noexcept;
    static std::pair<int, int>
    get_move_to(std::pair<int, int> from,
                const std::vector<std::pair<int, int>>& possible) noexcept;

public:
    Game() noexcept : board_(), current_player_(Player::White) {}

    [[nodiscard]] Player get_winner() const noexcept;
    void print_board() noexcept;
    void loop() noexcept;
};

#endif// PROSTERNO_GAME_GAME_H_
