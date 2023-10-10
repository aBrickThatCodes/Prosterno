#ifndef PROSTERNO_SCOREBOARD_SCOREBOARD_H
#define PROSTERNO_SCOREBOARD_SCOREBOARD_H

#include <filesystem>
#include <map>
#include <ostream>
#include <string>

namespace fs = std::filesystem;

class Scoreboard {
public:
  fs::path path_;
  std::map<std::string, int> scoreboard_;

public:
  Scoreboard() noexcept;
  void ReadFile(const fs::path &p) noexcept;
  ~Scoreboard() noexcept;

  void WhiteWon() { ++scoreboard_.at("white"); }

  void BlackWon() { ++scoreboard_.at("black"); }

  friend std::ostream &operator<<(std::ostream &o, Scoreboard &s) {
    return o << "White: " << s.scoreboard_.at("white")
             << " Black: " << s.scoreboard_.at("black");
  }
};

#endif // PROSTERNO_SCOREBOARD_SCOREBOARD_H
