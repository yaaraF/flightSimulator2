
#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "Command.h"


class PrintCommand : public Command {
public:
    PrintCommand(MySocket *mySocket);

    void doCommand();
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
