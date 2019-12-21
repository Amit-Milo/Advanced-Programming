//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__UNARYOPERATOR_H_
#define EX1__UNARYOPERATOR_H_

#include "../Expression.h"
class UnaryOperator: public Expression{
 protected:
  Expression* exp;
 public:
  UnaryOperator(Expression *_exp);
  virtual ~UnaryOperator();
};

#endif //EX1__UNARYOPERATOR_H_
