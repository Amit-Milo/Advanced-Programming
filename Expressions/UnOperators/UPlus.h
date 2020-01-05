//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__UPLUS_H_
#define EX1__UPLUS_H_

#include "UnaryOperator.h"
class UPlus: public UnaryOperator{
 public:
  UPlus(Expression *_exp);
  double calculate() override;
};

#endif //EX1__UPLUS_H_
