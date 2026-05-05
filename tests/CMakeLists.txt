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
        test_Initialization.cpp
        test_helpCommand.cpp
        test_calcWeight.cpp
        ../src/math.cpp
        ../src/App.cpp
        ../src/ConsoleMenu.cpp
        ../src/HelpCommand.cpp
        ../src/Initialization.cpp
        ../src/AddCommand.cpp
        ../src/RecommendCommand.cpp
        ../src/DisplayErrorClass.cpp
        ../src/CandidateProducts.cpp
        ../src/DataManager.cpp
)

target_include_directories(runTests PRIVATE ../src)
target_link_libraries(runTests GTest::gtest)
