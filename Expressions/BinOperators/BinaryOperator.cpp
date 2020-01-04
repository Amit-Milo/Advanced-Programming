//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "BinaryOperator.h"
BinaryOperator::~BinaryOperator() {
  delete this->left;
  delete this->right;
}
BinaryOperator::BinaryOperator(Expression *_left, Expression *_right) : left(_left), right(_right) {}
