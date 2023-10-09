cmake_minimum_required(VERSION 3.25)
project(Prosterno)

set(CMAKE_CXX_STANDARD 17)

add_executable(prosterno main.cpp Board/Board.cpp Board/Board.hpp Piece/Piece.hpp Piece/BlackPiece.cpp Piece/BlackPiece.hpp Piece/WhitePiece.cpp Piece/WhitePiece.hpp Game/Game.cpp Game/Game.hpp Scoreboard/Scoreboard.cpp Scoreboard/Scoreboard.hpp)