//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "BinaryOperator.h"
#include "Plus.h"
Plus::Plus(Expression *_left, Expression *_right) : BinaryOperator(_left, _right) {}
double Plus::calculate() {
  return this->left->calculate()+this->right->calculate();
}
