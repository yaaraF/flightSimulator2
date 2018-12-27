
#ifndef SIMULATORFLIGHT_COMMAND_H
#define SIMULATORFLIGHT_COMMAND_H

#include "MySocket.h"
#include "list"
#include "ShuntingYard.h"
using namespace std;

class Command{
protected:
    MySocket *mySocket;
    vector<string> parm;

    ShuntingYard *shuntingYard;
public:
    Command(MySocket *mySocket) : mySocket(mySocket) {
        this->shuntingYard = new ShuntingYard(this->mySocket);
    }


    virtual void doCommand()=0;
    void setList(vector<string> s){
        this->parm = s;
    }

};

#endif //SIMULATORFLIGHT_COMMAND_H