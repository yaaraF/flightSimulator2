

#ifndef SIMULATORFLIGHT_EXPRESSION_H
#define SIMULATORFLIGHT_EXPRESSION_H

#include <string>
#include <vector>


using namespace std;

class Expression {

public:
    virtual float calculate() = 0;

    virtual void setParm(vector<string> s) = 0;
};

#endif //SIMULATORFLIGHT_EXPRESSION_H
