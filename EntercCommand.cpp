
#include "EntercCommand.h"

EntercCommand::EntercCommand(MySocket *mySocket) : Command(mySocket) {}

void EntercCommand::doCommand() {
    int x;
    cin >> x;
}