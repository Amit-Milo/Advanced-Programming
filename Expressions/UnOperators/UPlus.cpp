//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "UPlus.h"
UPlus::UPlus(Expression *_exp) : UnaryOperator(_exp) {}
double UPlus::calculate() {
  return this->exp->calculate();
}
