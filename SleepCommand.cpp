
#include "SleepCommand.h"

void SleepCommand::doCommand() {
    int a = atoi((this->parm[0]).c_str());
    usleep(a);
}

SleepCommand::SleepCommand(MySocket *mySocket) : Command(mySocket) {}
