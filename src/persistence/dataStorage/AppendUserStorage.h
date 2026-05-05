//
// Created by geras on 05.05.2026.
//

#ifndef APPENDUSERSTORAGE_H
#define APPENDUSERSTORAGE_H

#include "IDataStorage.h"
#include "DataManager.h"
class AppendUserStorage : public IDataStorage{
private:
    int userId;
public:
    explicit AppendUserStorage( int userId);
    void execute(DataManager* dataManager) override;
};



#endif //APPENDUSERSTORAGE_H
