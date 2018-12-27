
#ifndef FLIGHTSIMOLATOR2_VARCOMMAND_H
#define FLIGHTSIMOLATOR2_VARCOMMAND_H


#include "Command.h"

class VarCommand : public Command {

public:
    VarCommand(MySocket *mySocket);

    void doCommand();

    void setList(vector<string> s) {
        this->parm = s;
    }

    VarCommand(MySocket *mySocket, const map<string, string> &addressVar);

};


#endif //SIMULATORFLIGHT_VARCOMMAND_H
