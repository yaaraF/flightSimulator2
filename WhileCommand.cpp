
#include "WhileCommand.h"

void WhileCommand::doCommand() {
    while (ConditionCommand::checkTheExpretion()) {
        ConditionCommand::DoTheCondtion();
    }

}

WhileCommand::WhileCommand(MySocket *mySocket, OrganizedData *data) : ConditionCommand(mySocket, data) {}
