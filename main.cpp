#include "Game/Game.h"
#include "Scoreboard/Scoreboard.h"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

void Usage(const std::string_view &s) {
  std::cout << "Prosterno - a terminal-based two-player prosterno game.\n";
  std::cout << "Usage:\n";
  std::cout << s << " [file|-h|[--help]]\n";
  std::cout << "path - path to a scoreboard file, in none entered defaults to \"scoreboard.txt\"" << std::endl;
  std::cout << "-h, --help - show this information\n";
  std::cout << "Rules for the game (in Polish) can be found at ";
  std::cout << "https://www.gamesfanatic.pl/2014/04/03/octonovem-polski-warcabowy-gipf/\n";
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
  Scoreboard s;

  switch (argc) {
  case 1:break;
  case 2: {
    std::string arg = argv[1];
    if (arg == "-h" || arg == "--help")
      Usage(argv[0]);

    s.ReadFile(arg);
    break;
  }
  default:Usage(argv[0]);
  }

  while (true) {
    Game g;
    g.Loop();
    std::cout << (g.GetWinner() == Game::Player::kWhite ? "White" : "Black") << " won!\n";
    switch (g.GetWinner()) {
    case Game::kNone:break;
    case Game::kWhite:std::cout << "White won!\n";
      s.WhiteWon();
    case Game::kBlack:std::cout << "Black won!\n";
      s.BlackWon();
    }
    std::cout << "Scores: " << s << '\n';

    while (true) {
      char choice;
      std::cout << "Play again? (y/n)" << std::flush;
      std::cin >> choice;
      switch (tolower(choice)) {
      case 'y':std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
      case 'n':return EXIT_SUCCESS;
      default:std::cout << "Please enter y or n\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
    }
  }
}
