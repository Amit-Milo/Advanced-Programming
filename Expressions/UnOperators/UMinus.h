//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__UMINUS_H_
#define EX1__UMINUS_H_

#include "UnaryOperator.h"
class UMinus: public UnaryOperator{
 public:
  UMinus(Expression *_exp);
  double calculate() override;
};

#endif //EX1__UMINUS_H_
