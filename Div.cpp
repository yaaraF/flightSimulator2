#include "Div.h"

float Div::calculate() {
    if(this->rightExp->calculate()==0){
        throw "can't divided by zero";
    }
    return this->leftExp->calculate()/this->rightExp->calculate();
}