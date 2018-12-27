
#include "OpenDataServerCommand.h"
#include <pthread.h>


void OpenDataServerCommand::doCommand() {


    if (this->parm.size() != 2) {
        throw "the parm are not match to openDataServer";
    }

    this->t->myMap = this->mySocket->getDAtaFromServer();
    this->t->stringPort = this->parm[0];
    pthread_t trid;
    int x = pthread_create(&trid, nullptr, MySocket::openFlightSocket, t);
    while (this->t->numID < 0) {}
    this->mySocket->setSimulatorID(this->t->numID);

}

OpenDataServerCommand::OpenDataServerCommand(MySocket *mySocket) : Command(mySocket) {}

OpenDataServerCommand::~OpenDataServerCommand() {
    delete (this->t);
}