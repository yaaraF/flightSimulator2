
#ifndef SIMULATORFLIGHT_OPENDATASERVERCOMMAND_H
#define SIMULATORFLIGHT_OPENDATASERVERCOMMAND_H

#include <iostream>
#include "Command.h"

class OpenDataServerCommand : public Command {
    struct exmp* t=new exmp();
public:
    OpenDataServerCommand(MySocket *mySocket);
    void doCommand();
    ~OpenDataServerCommand();

};

#endif //SIMULATORFLIGHT_OPENDATASERVERCOMMAND_H
