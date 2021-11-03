cmake_minimum_required(VERSION 3.17)
project(Scientific_Calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(Library/includes)

add_library(calclib SHARED
        includes/ArithmeticExprSolver.h
        includes/calclib.h
        includes/Calculator.h
        includes/ExprSolver.h
        includes/Matrix.h
        includes/MatrixExprSolver.h
        includes/SciCalculator.h
        includes/Token.h
        includes/tokens.h

        src/ArithmeticExprSolver.cpp
        src/calclib.cpp
        src/ExprSolver.cpp
        src/Matrix.cpp
        src/MatrixExprSolver.cpp
        src/SciCalculator.cpp
        src/Token.cpp
        src/tokens.cpp
        )

add_executable(Scientific_Calculator
        includes/ArithmeticExprSolver.h
        includes/calclib.h
        includes/Calculator.h
        includes/ExprSolver.h
        includes/Matrix.h
        includes/MatrixExprSolver.h
        includes/SciCalculator.h
        includes/Token.h
        includes/tokens.h
        src/ArithmeticExprSolver.cpp
        src/calclib.cpp
        src/ExprSolver.cpp
        src/Matrix.cpp
        src/MatrixExprSolver.cpp
        src/SciCalculator.cpp
        src/Token.cpp
        src/tokens.cpp
        main.cpp)
