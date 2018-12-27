
#ifndef SIMULATORFLIGHT_PLUS_H
#define SIMULATORFLIGHT_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {

public:
    Plus(Expression *rightexp, Expression *leftExp) : BinaryExpression(rightexp, leftExp) {};

    float calculate();

    void setParm(vector<string> s) {}

};


#endif //SIMULATORFLIGHT_PLUS_H
