cmake_minimum_required(VERSION 3.17)
project(Scientific_Calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(Library/includes)

add_executable(Scientific_Calculator
        Library/includes/ArithmeticExprSolver.h
        Library/includes/calclib.h
        Library/includes/Calculator.h
        Library/includes/ExprSolver.h
        Library/includes/Matrix.h
        Library/includes/MatrixExprSolver.h
        Library/includes/SciCalculator.h
        Library/includes/Token.h
        Library/includes/tokens.h
        Library/src/ArithmeticExprSolver.cpp
        Library/src/calclib.cpp
        Library/src/ExprSolver.cpp
        Library/src/Matrix.cpp
        Library/src/MatrixExprSolver.cpp
        Library/src/SciCalculator.cpp
        Library/src/Token.cpp
        Library/src/tokens.cpp
        Library/main.cpp)
