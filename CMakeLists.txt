cmake_minimum_required(VERSION 3.25)
project(Prosterno)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("-stdlib=libc++")

add_executable(prosterno main.cc Board/Board.cc Board/Board.h Piece/Piece.h Piece/BlackPiece.cc Piece/BlackPiece.h Piece/WhitePiece.cc Piece/WhitePiece.h Game/Game.cc Game/Game.h Scoreboard/Scoreboard.cc Scoreboard/Scoreboard.h)