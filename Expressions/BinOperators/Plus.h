//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__PLUS_H_
#define EX1__PLUS_H_

#include "BinaryOperator.h"
class Plus: public BinaryOperator{
 public:
  Plus(Expression *_left, Expression *_right);
  double calculate() override;
};
#endif //EX1__PLUS_H_
