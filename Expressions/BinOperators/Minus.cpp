//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "BinaryOperator.h"
#include "Minus.h"
Minus::Minus(Expression *_left, Expression *_right) : BinaryOperator(_left, _right) {}
double Minus::calculate() {
  return this->left->calculate()-this->right->calculate();
}
