#include "ExitCommand.h"


ExitCommand::ExitCommand(MySocket *mySocket) : Command(mySocket) {}

void ExitCommand::doCommand() {
    this->mySocket->exitSockets();
}