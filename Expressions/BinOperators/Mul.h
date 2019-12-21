//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__MUL_H_
#define EX1__MUL_H_

#include "BinaryOperator.h"
class Mul: public BinaryOperator{
 public:
  Mul(Expression *_left, Expression *_right);
  double calculate() override;
};

#endif //EX1__MUL_H_
