
#include "PrintCommand.h"


void PrintCommand::doCommand() {
    for (int i = 0; i < this->parm.size(); i++) {
        this->mySocket->print(this->parm[i]);
    }
}

PrintCommand::PrintCommand(MySocket *mySocket) : Command(mySocket) {}


