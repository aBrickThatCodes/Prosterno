#include "Scoreboard.h"

#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>

void Scoreboard::read_file(const fs::path& p) noexcept {
    path_ = p;

    if (!fs::exists(path_)) {
        std::cout << path_ << ": no such file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::fstream fin(path_);
    int w, b;
    if (fin >> w >> b) {
        scoreboard_.at("white") = w;
        scoreboard_.at("black") = b;
    } else {
        std::cout << "Scoreboard file " << path_ << " is corrupted" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Scoreboard::~Scoreboard() noexcept {
    std::fstream fout(path_, std::ios::out | std::ios::trunc);
    fout << scoreboard_.at("white") << ' ' << scoreboard_.at("black")
         << std::flush;
}

Scoreboard::Scoreboard() noexcept : path_("scoreboard.txt") {
    if (!fs::exists(path_)) {
        scoreboard_ = {{"white", 0}, {"black", 0}};
        return;
    }

    std::fstream fin(path_);
    int w, b;
    if (fin >> w >> b) {
        scoreboard_.insert({"white", w});
        scoreboard_.insert({"black", b});
    } else {
        std::cout << "Scoreboard file " << path_ << " is corrupted" << std::endl;
        exit(EXIT_FAILURE);
    }
}
