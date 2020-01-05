//
// Created by yoav on 14/11/2019.
//

#include "Variable.h"
double Variable::calculate() {
  return this->value;
}
Variable::Variable(const string &_name, double _value) : name(_name), value(_value) {}

Variable &Variable::operator++() {
  this->value++;
  return *this;
}
Variable &Variable::operator++(int) {
  this->value++;
  return *this;
}
Variable &Variable::operator--() {
  this->value--;
  return *this;
}
Variable &Variable::operator--(int) {
  this->value--;
  return *this;
}
Variable &Variable::operator+=(const double d) {
  this->value += d;
  return *this;
}
Variable &Variable::operator-=(const double d) {
  this->value -= d;
  return *this;
}
