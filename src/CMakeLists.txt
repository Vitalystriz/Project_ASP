add_executable(RecommendationApp
        DataManager.h
        command/ICommand.h
        menu/IMenu.h
        run/App.h
        run/Initialization.h
        menu/ConsoleMenu.h

        Similarity.h
        CandidateProducts.h
        RecommendationList.h

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

        Similarity.cpp
        CandidateProducts.cpp
        RecommendationList.cpp
        persistence/dataAction/IDataAction.h
        persistence/dataAction/AppendUserAction.h
        persistence/dataAction/AppendUserAction.cpp
        persistence/dataAction/AppendProductAction.cpp
        persistence/dataAction/AppendProductAction.h
        persistence/dataStorage/IDataStorage.h
        persistence/dataStorage/AppendUserStorage.cpp
        persistence/dataStorage/AppendUserStorage.h
        persistence/dataStorage/AppendProdcutStorage.cpp
        persistence/dataStorage/AppendProdcutStorage.h
        run/LoadingData.cpp
        run/LoadingData.h
)

# Tell the compiler to treat the current directory (src)
# as the base for all #include directives
target_include_directories(RecommendationApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})