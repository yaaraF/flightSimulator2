
#ifndef HOPEGOOD_SLEEPCOMMAND_H
#define HOPEGOOD_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand : public Command {

public:
    SleepCommand(MySocket *mySocket);

    void doCommand();
};

#endif //HOPEGOOD_SLEEPCOMMAND_H
