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
        # --- Test Files ---
        test_main.cpp
        test_nextCommand.cpp
        test_getArgs.cpp
        test_Initialization.cpp
        test_helpCommand.cpp

        # --- Source Files (Everything EXCEPT src/run/main.cpp) ---
        ../src/run/Initialization.cpp
        ../src/run/App.cpp

        ../src/menu/ConsoleMenu.cpp

        ../src/command/DisplayErrorClass.cpp
        ../src/command/HelpCommand.cpp
        ../src/command/AddCommand.cpp
        ../src/command/RecommendCommand.cpp

        ../src/DataManager.cpp
)

target_include_directories(runTests PRIVATE ../src)
target_link_libraries(runTests GTest::gtest)