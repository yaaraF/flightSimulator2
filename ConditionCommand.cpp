
#include "ConditionCommand.h"


bool ConditionCommand::checkTheExpretion() {
    Expression *e1 = this->shuntingYard->infixToPostfix(this->parm[0]);
    Expression *e2 = this->shuntingYard->infixToPostfix(this->parm[2]);


    if (this->parm[1] == "<") {
        return e1->calculate() < e2->calculate();
    }
    if (this->parm[1] == ">") {
        return e1->calculate() > e2->calculate();
    }
    if (this->parm[1] == "==") {
        return e1->calculate() == e2->calculate();
    }
    if (this->parm[1] == ">=") {
        return e1->calculate() >= e2->calculate();
    }
    if (this->parm[1] == "<=") {
        return e1->calculate() <= e2->calculate();
    }
    if (this->parm[1] == "!=") {
        return e1->calculate() != e2->calculate();
    }

}

void ConditionCommand::add(string s, Expression *e) {
    this->data->add(s, e);
}

map<string, Expression *> ConditionCommand::getMap() {
    return this->data->getMap();
}

ConditionCommand::ConditionCommand(MySocket *mySocket, OrganizedData *data) : Command(mySocket), data(data) {}

void ConditionCommand::DoTheCondtion() {


    if (this->check) {
        for (int i = 4; i < this->parm.size(); i++) {
            this->data->lexer(this->parm[i]);

        }
        check = false;
    }

    this->data->parser();

}

