
#ifndef SIMULATORFLIGHT_NUMBER_H
#define SIMULATORFLIGHT_NUMBER_H

#include "Expression.h"

class Number : public Expression {
    float value;
public:
    Number(float value);

    float calculate();

    void setParm(vector<string> s) {

    }


};

#endif //SIMULATORFLIGHT_NUMBER_H
