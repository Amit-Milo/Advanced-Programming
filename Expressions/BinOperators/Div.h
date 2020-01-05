//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__DIV_H_
#define EX1__DIV_H_

#include "BinaryOperator.h"
class Div: public BinaryOperator{
 public:
  Div(Expression *_left, Expression *_right);
  double calculate() override;
};

#endif //EX1__DIV_H_
