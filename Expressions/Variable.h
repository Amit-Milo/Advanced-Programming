//
// Created by yoav on 14/11/2019.
//

#ifndef EX1__VARIABLE_H_
#define EX1__VARIABLE_H_

#include <string>
#include "Expression.h"
class Variable: public Expression{
 private:
  string name;
  double value;
 public:
  double calculate() override;
  //operators
  Variable(const string &_name, double _value);
  Variable& operator++();
  Variable& operator++(int);
  Variable& operator--();
  Variable& operator--(int);
  Variable& operator+=(const double d);
  Variable& operator-=(const double d);
};

#endif //EX1__VARIABLE_H_
