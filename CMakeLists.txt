cmake_minimum_required(VERSION 3.21)
project(TetrisExam)

set(CMAKE_CXX_STANDARD 17)

add_executable(TetrisExam src/main.cpp src/GameState/TetrisPiece.cpp src/GameState/TetrisPiece.h src/GameState/TetrisGridState.cpp src/GameState/TetrisGridState.h src/GameState/GridCellState.cpp src/GameState/GridCellState.h src/RunningGame/RunningGame.cpp src/RunningGame/RunningGame.h src/GameState/TetrisGameState.cpp src/GameState/TetrisGameState.h src/GUI/GameRenderer.cpp src/GUI/GameRenderer.h src/Setup/GameSaver.cpp src/Setup/GameSaver.h src/Setup/GameLoader.cpp src/Setup/GameLoader.h src/Logic/TetrisPieceGenerator.cpp src/Logic/TetrisPieceGenerator.h src/Logic/GameLogicManager.cpp src/Logic/GameLogicManager.h src/RunningGame/TetrisGameManager.cpp src/RunningGame/TetrisGameManager.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/libs/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/def/libs/SFML/include)
target_link_libraries (TetrisExam sfml-graphics sfml-window sfml-system sfml-audio)
