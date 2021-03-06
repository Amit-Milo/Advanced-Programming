//
// Created by yoav on 14/11/2019.
//

#include "Div.h"

Div::Div(Expression *_left, Expression *_right) : BinaryOperator(_left, _right) {

}
double Div::calculate() {
  double denominator = this->right->calculate();
  if (denominator == 0) { //do not allow division by zero
    throw "division by 0 error";
  }
  //else, the division is ok.
  return this->left->calculate() / denominator;
}
