
#include "Plus.h"

float Plus::calculate() {
    return this->leftExp->calculate() + this->rightExp->calculate();
}