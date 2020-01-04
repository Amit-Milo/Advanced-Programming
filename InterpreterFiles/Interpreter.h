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
  Container* container;
 public:
  Interpreter(Container *container);
  virtual ~Interpreter();
  /////////main func
  double evaluate(string s);
  void setVariables(string s);
  /////////
  Expression *interpret(string s);
  void printVariables();
};

#endif //EX1__INTERPRETER_H_
