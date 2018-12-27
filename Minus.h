
#ifndef SIMULATORFLIGHT_MINUS_H
#define SIMULATORFLIGHT_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *rightexp, Expression *leftExp) : BinaryExpression(rightexp, leftExp) {};

    float calculate();

    void setParm(vector<string> s) {}

};


#endif //SIMULATORFLIGHT_MINUS_H