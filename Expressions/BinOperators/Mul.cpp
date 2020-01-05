//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "BinaryOperator.h"
#include "Mul.h"
Mul::Mul(Expression *_left, Expression *_right) : BinaryOperator(_left, _right) {}
double Mul::calculate() {
  return this->left->calculate()*this->right->calculate();
}
