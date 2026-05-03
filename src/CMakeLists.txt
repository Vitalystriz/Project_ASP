
add_executable(RecommendationApp
        ../src/ICommand.h
        ../src/IMenu.h
        ../src/App.h
        ../src/Initialization.h
        ../src/ConsoleMenu.h

        ../src/DisplayErrorClass.h
        ../src/HelpCommand.h
        ../src/AddCommand.h
        ../src/RecommendCommand.h
        ../src/main.cpp

        ../src/Initialization.cpp
        ../src/App.cpp

        ../src/ConsoleMenu.cpp

        ../src/DisplayErrorClass.cpp
        ../src/HelpCommand.cpp

        ../src/AddCommand.cpp

        ../src/RecommendCommand.cpp


)