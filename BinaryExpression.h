
#ifndef SIMULATORFLIGHT_BINARYEXPRESSION_H
#define SIMULATORFLIGHT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
protected:
    Expression* rightExp;
    Expression* leftExp;
public:
    BinaryExpression(Expression *rightExp, Expression *leftExp) : rightExp(leftExp), leftExp(rightExp){};

    virtual float calculate()=0;

    void setParm(vector<string>s) {}

};


#endif //SIMULATORFLIGHT_BINARYEXPRESSION_H
