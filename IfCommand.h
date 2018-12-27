

#ifndef SIMULATORFLIGHT_IFCOMMAND_H
#define SIMULATORFLIGHT_IFCOMMAND_H


#include "ConditionCommand.h"


class IfCommand : public ConditionCommand {

public:
    IfCommand(MySocket *mySocket, OrganizedData *data);

    void doCommand();

};


#endif //SIMULATORFLIGHT_IFCOMMAND_H

