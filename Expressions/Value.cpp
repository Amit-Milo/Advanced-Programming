//
// Created by yoav on 14/11/2019.
//

#include "Value.h"
double Value::GetVal() const {
  return val;
}
Value::Value(double _val) : val(_val) {}
double Value::calculate() {
  return this->val;
}
