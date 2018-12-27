
#ifndef SIMULATORFLIGHT_SHUNTINGYARD_H
#define SIMULATORFLIGHT_SHUNTINGYARD_H

using namespace std;

#include <iostream>
#include "Expression.h"
#include "MySocket.h"
#include <vector>

class ShuntingYard {
    MySocket* data;
    vector<Expression*> toBeDeleted;
public:
    ShuntingYard(MySocket* data){
        this->data = data;
    }
    vector<string> splitString(string str);
    int getPriority(string C);
    Expression*  infixToPostfix(string str);
    Expression* stringToExpression(vector<string>  postfix);
    bool isOperator(char s);
    vector<string> swapVars(vector<string> withVars);
    vector<string> checkMinus(vector<string> str);
    ~ShuntingYard();
};

#endif //SIMULATORFLIGHT_SHUNTINGYARD_H
