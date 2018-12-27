
#ifndef SIMULATORFLIGHT_COMMANDEXPRESSION_H
#define SIMULATORFLIGHT_COMMANDEXPRESSION_H

#include <list>
#include "Command.h"
#include "Expression.h"


class CommandExpression : public Expression {
    Command *command;


public:
    CommandExpression(Command *command) {
        this->command = command;
    }

    float calculate() {
        this->command->doCommand();
    }

    void setParm(vector<string> s) {
        this->command->setList(s);
    }

};

#endif //SIMULATORFLIGHT_COMMANDEXPRESSION_H
