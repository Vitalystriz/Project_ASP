//
// Created by vitaly on 04.05.2026.
//

#ifndef APPENDUSERACTION_H
#define APPENDUSERACTION_H

#include "IDataAction.h"

class AppendUserAction : public IDataAction {
private:
    int userId;
  public:
    explicit AppendUserAction(int userId);
    void execute(DataManager* dataManager) override;
    void displayError() override;
};

#endif //APPENDUSERACTION_H
