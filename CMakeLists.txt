cmake_minimum_required(VERSION 3.25)
project(Prosterno)

set(CMAKE_CXX_STANDARD 17)

add_executable(prosterno main.cpp Board/Board.cpp Board/Board.h Piece/Piece.h Piece/BlackPiece.cpp Piece/BlackPiece.h Piece/WhitePiece.cpp Piece/WhitePiece.h Game/Game.cpp Game/Game.h Scoreboard/Scoreboard.cpp Scoreboard/Scoreboard.h)