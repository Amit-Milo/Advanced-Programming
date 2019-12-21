//
// Created by yoav on 14/11/2019.
//

#include "Div.h"

Div::Div(Expression *_left, Expression *_right) : BinaryOperator(_left, _right) {

}
double Div::calculate() {
  double denominator = this->right->calculate();
  if (denominator==0){
    throw "division by 0 error";
  }
  return this->left->calculate() / this->right->calculate();
}
