#include "Game.hpp"

#include "../Piece/BlackPiece.hpp"
#include "../Piece/WhitePiece.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>

void Game::loop() noexcept {
    print_board();
    while (get_winner() == None) {
        std::pair<int, int> from;
        std::vector<std::pair<int, int>> possible;

        std::cout << "Current player: "
                  << (current_player_ == White ? "white\n" : "black\n");

        while (true) {
            from = get_move_from();
            possible = board_.get_piece(from)->get_moves();

            auto it = std::remove_if(possible.begin(), possible.end(),
                                     [=](std::pair<int, int>& p) {
                                         return board_.get_piece(p) != nullptr;
                                     });
            possible.erase(it, possible.end());

            if (!possible.empty()) {
                break;
            }

            std::cout << "Piece (" << from.second << ',' << from.first
                      << ") can not make a move\n";
        }

        auto to = get_move_to(from, possible);
        board_.make_move(from, to);
        current_player_ = current_player_ == White ? Black : White;
        print_board();
    }
}

Game::Player Game::get_winner() const noexcept {
    if (board_.white_pieces_ == 0) {
        return Black;
    } else if (board_.black_pieces_ == 0) {
        return White;
    }
    return Game::None;
}

void Game::print_board() noexcept {
    for (int i = 0; i < board_.board_.size(); ++i) {
        for (int j = 0; j < board_.board_.size(); ++j) {
            if ((i + j) % 2 != 0) {
                std::cout << "\033[7m";
            }

            if (board_.get_piece({i + 1, j + 1}) != nullptr) {
                std::cout << "O";
            } else {
                std::cout << " ";
            }

            if ((i + j) % 2 != 0) {
                std::cout << "\033[0m";
            }
        }
        std::cout << '\n';
    }
    std::cout << std::flush;
}

std::pair<int, int> Game::get_move_from() noexcept {
    while (true) {
        std::pair<int, int> pos;

        while (true) {
            std::cout << "X coordinate of piece to move (1-8): " << std::flush;
            std::cin >> pos.second;

            if (!std::cin.fail()) {
                break;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input, try again\n";
        }

        if (pos.second - 1 < 0 || pos.second > board_.board_.size()) {
            std::cout << pos.second << " is outside the board\n";
            continue;
        }

        while (true) {
            std::cout << "Y coordinate of piece to move (1-8): " << std::flush;
            std::cin >> pos.first;

            if (!std::cin.fail()) {
                break;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input, try again\n";
        }
        if (pos.first - 1 < 0 || pos.first > board_.board_.size()) {
            std::cout << pos.first << " is outside the board\n";
            continue;
        }

        auto& p = board_.get_piece(pos);
        switch (current_player_) {
            case White:
                if (dynamic_cast<WhitePiece*>(p.get()) == nullptr) {
                    std::cout << "There is no white piece at (" << pos.second << ','
                              << pos.first << ")\n";
                    continue;
                }
                break;

            case Black:
                if (dynamic_cast<BlackPiece*>(p.get()) == nullptr) {
                    std::cout << "There is no black piece at (" << pos.second << ','
                              << pos.first << ")\n";
                    continue;
                }
                break;
            case None:
                break;
        }

        return pos;
    }
}

std::pair<int, int>
Game::get_move_to(std::pair<int, int> from,
                  const std::vector<std::pair<int, int>>& possible) noexcept {
    while (true) {
        std::cout << "Piece: (" << from.second << ',' << from.first << ")\n";

        std::cout << "Possible moves: ";
        for (int i = 0; i < possible.size(); ++i) {
            auto& p = possible.at(i);
            std::cout << (i + 1) << ". (" << p.second << ',' << p.first << ") ";
        }
        std::cout << '\n';

        int choice = 0;
        while (true) {
            while (true) {
                std::cout << "Which move to make: " << std::flush;
                std::cin >> choice;

                if (!std::cin.fail()) {
                    break;
                }

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Incorrect input, try again\n";
            }

            if (choice > 0 && choice < possible.size() + 1) {
                break;
            }

            std::cout << choice << " is not a correct option\n";
        }

        return possible.at(choice - 1);
    }
}
