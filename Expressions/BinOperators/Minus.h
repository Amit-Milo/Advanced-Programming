//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__MINUS_H_
#define EX1__MINUS_H_

#include "BinaryOperator.h"
class Minus: public BinaryOperator{
 public:
  Minus(Expression *_left, Expression *_right);
  double calculate() override;
};

#endif //EX1__MINUS_H_
