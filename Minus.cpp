

#include "Minus.h"

float Minus::calculate() {
    return this->leftExp->calculate() - this->rightExp->calculate();
}
