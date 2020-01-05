//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__BINARYOPERATOR_H_
#define EX1__BINARYOPERATOR_H_

#include "../Expression.h"
class BinaryOperator : public Expression {
 protected:
  Expression *left;
  Expression *right;
 public:
  BinaryOperator(Expression *_left, Expression *_right);
  virtual ~BinaryOperator();
};

#endif //EX1__BINARYOPERATOR_H_
