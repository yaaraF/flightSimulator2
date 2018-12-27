
#include "VarCommand.h"


void VarCommand::doCommand() {
    if (this->parm[2] == "bind" || this->parm[2] == "\"bind") {
        this->mySocket->addBind(this->parm[0], this->parm[3]);
        return;
    }

    Expression *exp = this->shuntingYard->infixToPostfix(this->parm[2]);
    float temp = exp->calculate();
    this->mySocket->addVar(this->parm[0], temp);


}

VarCommand::VarCommand(MySocket *mySocket) : Command(mySocket) {}
