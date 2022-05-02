cmake_minimum_required(VERSION 3.18)
project(TetrisExam)

set(CMAKE_CXX_STANDARD 17)

add_executable(TetrisExam
        src/main.cpp
        src/GameState/TetrisShape.cpp
        src/GameState/TetrisShape.h
        src/GameState/Grid.cpp
        src/GameState/Grid.h
        src/GameState/GridCellState.cpp
        src/GameState/GridCellState.h
        src/RunningGame/Game.cpp
        src/RunningGame/Game.h
        src/GameState/GameState.cpp
        src/GameState/GameState.h
        src/View/GameRenderer.cpp
        src/View/GameRenderer.h
        src/Setup/GameSaver.cpp
        src/Setup/GameSaver.h
        src/Setup/GameLoader.cpp
        src/Setup/GameLoader.h
        src/Logic/TetrsPiece/TetrisPieceGenerator.cpp
        src/Logic/TetrsPiece/TetrisPieceGenerator.h
        src/Logic/GameLogic.cpp
        src/Logic/GameLogic.h
        src/RunningGame/GameManager.cpp
        src/RunningGame/GameManager.h
        src/View/GridDrawer.cpp
        src/View/GridDrawer.h
        src/SplitScreen/MultiScreenProvider.cpp
        src/SplitScreen/MultiScreenProvider.h
        src/Input/TetrisPlayerInputManager.cpp
        src/Input/TetrisPlayerInputManager.h
        src/Input/KeyboardInput.cpp
        src/Input/KeyboardInput.h
        src/Input/InputType.h
        src/Logic/GridLogic.cpp
        src/Logic/GridLogic.h
        src/GameState/TetrisTile.cpp
        src/GameState/TetrisTile.h
        src/Logic/TetrsPiece/TetrisShapeBuilder.cpp
        src/Logic/TetrsPiece/TetrisShapeBuilder.h
        src/Logic/TetrsPiece/TetrisPieceLogic.cpp
        src/Logic/TetrsPiece/TetrisPieceLogic.h
        src/Logic/GameLogicTimer.cpp
        src/Logic/GameLogicTimer.h
        src/GameState/TetrisPiece.cpp
        src/GameState/TetrisPiece.h src/Input/KeyboardLayout.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/libs/SFML/lib/cmake/SFML)

if (WIN32)
    find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
endif()

include_directories(c:/def/libs/SFML/include)
target_link_libraries (TetrisExam sfml-graphics sfml-window sfml-system sfml-audio)
