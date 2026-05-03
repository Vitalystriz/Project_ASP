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
        ../src/command/ICommand.h
        ../src/menu/IMenu.h
        ../src/run/App.h
        ../src/run/Initialization.h
        ../src/menu/ConsoleMenu.h

        ../src/command/DisplayErrorClass.h
        ../src/command/HelpCommand.h
        ../src/command/AddCommand.h
        ../src/command/RecommendCommand.h
        ../src/run/main.cpp

        ../src/run/Initialization.cpp
        ../src/run/App.cpp

        ../src/menu/ConsoleMenu.cpp

        ../src/command/DisplayErrorClass.cpp
        ../src/command/HelpCommand.cpp

        ../src/command/AddCommand.cpp

        ../src/command/RecommendCommand.cpp
        ../src/DataManager.cpp

        ../src/DataManager.h

        test_nextCommand.cpp
        test_getArgs.cpp
        test_Initialization.cpp
        test_helpCommand.cpp
        #../src/main.cpp
) # change to relevant files
target_include_directories(runTests PRIVATE ../src)
target_link_libraries(runTests GTest::gtest) # change to relevant files