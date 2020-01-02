//
// Created by yoav on 14/11/2019.
//

#include "../Expression.h"
#include "UnaryOperator.h"
UnaryOperator::UnaryOperator(Expression *_exp) : exp(_exp) {}
UnaryOperator::~UnaryOperator() {
  delete exp;
}
