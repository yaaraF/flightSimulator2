
#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "ConditionCommand.h"

class WhileCommand : public ConditionCommand {
public:
    WhileCommand(MySocket *mySocket, OrganizedData *data);

    void doCommand();
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
