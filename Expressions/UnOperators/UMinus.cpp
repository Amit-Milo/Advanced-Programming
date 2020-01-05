//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "UMinus.h"
UMinus::UMinus(Expression *_exp) : UnaryOperator(_exp) {}
double UMinus::calculate() {
  return -(this->exp->calculate());
}
