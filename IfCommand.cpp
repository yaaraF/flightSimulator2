
#include "IfCommand.h"

void IfCommand::doCommand() {

    if (checkTheExpretion()) {
        ConditionCommand::DoTheCondtion();
    }

}

IfCommand::IfCommand(MySocket *mySocket, OrganizedData *data) : ConditionCommand(mySocket, data) {

}







