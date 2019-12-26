//
// Created by yoav on 16/11/2019.
//
#include <regex>
#include <iostream>

#include "Interpreter.h"
#include "CalculationTokensCreatorChecker.h"
#include "TokensToExpressionConverter.h"

Interpreter::Interpreter() {
  this->variables = new map<string, double>;
}
Interpreter::~Interpreter() {
  delete variables;
}

///////////
double Interpreter::evaluate(string s) {
  return this->interpret(s)->calculate();
}
///////////

Expression *Interpreter::interpret(string s) {
  //string to tokens list
  CalculationTokensCreatorChecker cvcc;
  list<pair<string, int>> *tokens = cvcc.createTokensList(s, variables);
  //list to expression
  TokensToExpressionConverter ttec;
  Expression *result = ttec.tokensToExpression(tokens, variables);
  //release memory and return
  delete tokens;
  return result;
}

void Interpreter::addVar(string name, double value) {
  this->variables->insert({name, value});
}
void Interpreter::changeVar(string name, double newValue) {
  this->variables->at(name) = newValue;
}


/////////////////////////////////////////////////////////////////////////////////

void Interpreter::setVariables(string s) {
  VarsSetter vs;
  vs.setVariables(s, this->variables);
}

void Interpreter::printVariables() {
  for (const auto &myPair : *variables) {
    std::cout << myPair.first << "," << myPair.second << "\n";
  }
}

void Interpreter::replaceVarsWithNums(list<pair<string, int>> *tokens) {
  std::list<pair<string, int>>::iterator it; //iterator for tokens list
  for (it = tokens->begin(); it != tokens->end(); it++) {
    // Access the object through iterator
    int flag = it->second;
    if (flag == VARIABLE) {
      it->first = to_string(variables->at(it->first));
      it->second = NUMBER;
    }
  }
}