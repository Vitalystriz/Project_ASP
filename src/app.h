//
// Created by geras on 28.04.2026.
//

#ifndef APP_H
#define APP_H

#include <map>
#include <string>
#include <IMenu.h>
namespace app {
    class app {
        private:
            int** matrix = nullptr;
            IMenu* menu;
            std::map<int,ICommand*> map{};
        public:
            explicit app(int** matrix, IMenu* menu, std::map<int, ICommand*> map);
            void run();
    };
}




#endif //APP_H
