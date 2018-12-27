
#ifndef UNTITLED12_EXITCOMMAND_H
#define UNTITLED12_EXITCOMMAND_H

#include "Command.h"

class ExitCommand : public Command {
public:
    ExitCommand(MySocket *mySocket);

    void doCommand();
};


#endif //UNTITLED12_EXITCOMMAND_H
