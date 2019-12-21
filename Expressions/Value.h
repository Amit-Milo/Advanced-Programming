//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__VALUE_H_
#define EX1__VALUE_H_

#include "Expression.h"
class Value: public Expression{
 private:
  double val;
 public:
  double GetVal() const;
  Value(double _val);
  double calculate() override;
};

#endif //EX1__VALUE_H_
