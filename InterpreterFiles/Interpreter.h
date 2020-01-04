//
// Created by yoav on 16/11/2019.
//

#ifndef EX1__INTERPRETER_H_
#define EX1__INTERPRETER_H_

#include <regex>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include "../Expressions/Expression.h"
#include "../Containers/MapsContainer.h"
#include "CalculationTokensCreatorChecker.h"
#include "TokensToExpressionConverter.h"
#include "VarsSetter.h"

#define BRACE 1
#define OPERATOR 2
#define OTHER 3

class Interpreter {
 private:
  Container *container;
 public:
  Interpreter(Container *container);
  /**
   * the main function. interpret and calculate it.
   * @param s the expression as a string.
   * @return the expression's value.
   */
  double evaluate(string s);
  /**
   * convert the input expression as a string to an expression object.
   * @param s the input expression as a string
   * @return s as an expression object
   */
  Expression *interpret(string s);

  void setVariables(string s); //TODO delete this func and all its related files
};

#endif //EX1__INTERPRETER_H_
