
#ifndef HOPEGOOD_ENTERCCOMMAND_H
#define HOPEGOOD_ENTERCCOMMAND_H

#include "Command.h"

class EntercCommand : public Command {
public:
    EntercCommand(MySocket *mySocket);

    void doCommand();


};


#endif //HOPEGOOD_ENTERCCOMMAND_H
