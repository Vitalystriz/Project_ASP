add_executable(RecommendationApp
        command/ICommand.h
        menu/IMenu.h
        run/App.h
        run/Initialization.h
        menu/ConsoleMenu.h

        command/DisplayErrorClass.h
        command/HelpCommand.h
        command/AddCommand.h
        command/RecommendCommand.h

        run/main.cpp
        run/Initialization.cpp
        run/App.cpp

        menu/ConsoleMenu.cpp

        command/DisplayErrorClass.cpp
        command/HelpCommand.cpp
        command/AddCommand.cpp
        command/RecommendCommand.cpp

        DataManager.cpp
        DataManager.h
)

# Tell the compiler to treat the current directory (src)
# as the base for all #include directives
target_include_directories(RecommendationApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})