
#include "CreateCommandMap.h"
#include "OrganizedData.h"

CreateCommandMap::CreateCommandMap() {
    this->mySocket = new MySocket();
    this->commands.insert(pair<string, Expression *>
                                  ("openDataServer",
                                   new CommandExpression(new OpenDataServerCommand(this->mySocket))));
    this->commands.insert(
            pair<string, Expression *>
                    ("connect", new CommandExpression(new ConnectCommand(this->mySocket))));
    this->commands.insert(pair<string, Expression *>("sleep", new CommandExpression(new SleepCommand(this->mySocket))));
    this->commands.insert(
            pair<string, Expression *>
                    ("EnterC", new CommandExpression(new EntercCommand(this->mySocket))));
    this->commands.insert(pair<string, Expression *>
                                  ("exit", new CommandExpression(new ExitCommand(this->mySocket))));

    this->ifCommand = new IfCommand(this->mySocket, new OrganizedData(this->getMapCommand()));
    this->ifCommand->add("if", new CommandExpression(new IfCommand(this->mySocket, new OrganizedData(this->getMapCommand()))));


    this->commands.insert(pair<string, Expression *>
                                  ("if", new CommandExpression(
                                          new IfCommand(this->mySocket, new OrganizedData(ifCommand->getMap())))));
    this->commands.insert(pair<string, Expression *>
                                  ("var", new CommandExpression(new VarCommand(this->mySocket))));
    this->commands.insert(pair<string, Expression *>
                                  ("print", new CommandExpression(new PrintCommand(this->mySocket))));

    this->whileCommand = new WhileCommand(this->mySocket, new OrganizedData(this->getMapCommand()));
    this->whileCommand->add("while",
                 new CommandExpression(new WhileCommand(this->mySocket, new OrganizedData(this->getMapCommand()))));

    this->commands.insert(pair<string, Expression *>("while", new CommandExpression(
            new WhileCommand(this->mySocket, new OrganizedData(whileCommand->getMap())))));


}

map<string, Expression *> CreateCommandMap::getMapCommand() {

    return this->commands;
}

CreateCommandMap::~CreateCommandMap() {
    delete (this->ifCommand);
    delete (this->whileCommand);
}
