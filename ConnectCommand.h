
#ifndef SIMULATORFLIGHT_CONNECTCOMMAND_H
#define SIMULATORFLIGHT_CONNECTCOMMAND_H

#include "Command.h"


class ConnectCommand : public Command {
public:
    ConnectCommand(MySocket *mySocket);


    void doCommand();

    void setList(vector<string> s) {
        this->parm = s;
    }
};

#endif //SIMULATORFLIGHT_CONNECTCOMMAND_H
