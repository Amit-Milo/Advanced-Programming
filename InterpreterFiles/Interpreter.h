//
// Created by yoav on 16/11/2019.
//

#ifndef EX1__INTERPRETER_H_
#define EX1__INTERPRETER_H_

#include <string>
#include <map>
#include <list>
#include "../Expressions/Expression.h"
#include "VarsSetter.h"


#define BRACE 1
#define OPERATOR 2
#define OTHER 3

class Interpreter {
 private:
  map<string, double> *variables;
 public:
  Interpreter();
  Expression *interpret(string s);
  void setVariables(string s);
  virtual ~Interpreter();
  void printVariables();
  void replaceVarsWithNums(list<pair<string, int>> *tokens);
};

#endif //EX1__INTERPRETER_H_
