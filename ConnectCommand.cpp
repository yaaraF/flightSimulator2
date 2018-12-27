
#include "ConnectCommand.h"


ConnectCommand::ConnectCommand(MySocket *mySocket) : Command(mySocket) {}

void ConnectCommand::doCommand() {

    if (this->parm.size() != 2) {
        throw "there is no match of parm to connect command";
    }

    this->mySocket->conectToSimolator(this->parm);
}


