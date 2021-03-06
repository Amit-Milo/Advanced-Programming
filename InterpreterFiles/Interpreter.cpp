//
// Created by yoav on 16/11/2019.
//


#include "Interpreter.h"


double Interpreter::evaluate(string s) {
  return this->interpret(s)->calculate();
}

Expression *Interpreter::interpret(string s) {
  //string to tokens list
  CalculationTokensCreatorChecker cvcc;
  list<pair<string, int>> *tokens = cvcc.createTokensList(s, container);
  //list to expression
  TokensToExpressionConverter ttec;
  Expression *result = ttec.tokensToExpression(tokens, container);
  //release memory and return
  delete tokens;
  return result;
}


Interpreter::Interpreter(Container *container) : container(container) {}