

#include "Mult.h"

float Mult::calculate() {
    return this->leftExp->calculate() * this->rightExp->calculate();
}