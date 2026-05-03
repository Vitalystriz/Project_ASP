cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(runTests
        test_main.cpp
        test_nextCommand.cpp
        test_getArgs.cpp
        ../src/math.cpp
        ../src/App.cpp
        ../src/App.h
        ../src/ConsoleMenu.cpp
        ../src/IMenu.h
        ../src/ICommand.h
        ../src/HelpCommand.cpp
        ../src/HelpCommand.cpp
        ../src/HelpCommand.cpp
        ../src/HelpCommand.cpp
        ../src/Initialization.cpp
        ../src/Initialization.h
        ../src/Initialization.h
        ../src/Initialization.h
        ../src/Initialization.h
        ../src/ConsoleMenu.h
        ../src/HelpCommand.h
        ../src/HelpCommand.cpp
        ../src/AddCommand.cpp
        ../src/AddCommand.h
        ../src/AddCommand.h
        ../src/HelpCommand.cpp
        ../src/AddCommand.h
        ../src/RecommendCommand.cpp
        ../src/RecommendCommand.h
        ../src/DisplayErrorClass.cpp
        ../src/DisplayErrorClass.h
        test_nextCommand.cpp
        test_getArgs.cpp
        test_Initialization.cpp
        test_helpCommand.cpp
        #../src/main.cpp
) # change to relevant files
target_include_directories(runTests PRIVATE ../src)
target_link_libraries(runTests GTest::gtest) # change to relevant files