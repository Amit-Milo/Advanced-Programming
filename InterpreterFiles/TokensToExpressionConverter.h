//
// Created by yoav on 17/11/2019.
//

#ifndef EX1__TOKENSTOEXPRESSIONCONVERTER_H_
#define EX1__TOKENSTOEXPRESSIONCONVERTER_H_

#include <list>
#include <string>
#include <map>
#include <stack>
#include <deque>
#include "VarsSetter.h"
#include "../Expressions/Expression.h"
#include "CalculationTokensCreatorChecker.h"

class TokensToExpressionConverter {
 public:
  Expression *tokensToExpression(list<pair<string, int>> *tokens, map<string,double>* variables);
  stack<pair<string,int>>* tokensToStack(list<pair<string, int>> *tokens);
  Expression *stackToExpression(stack<pair<string,int>>* calcStack, map<string,double>* variables);
  int compareOperators(string s1, string s2);
  void printStack(stack<pair<string,int>>* s);
};

#endif //EX1__TOKENSTOEXPRESSIONCONVERTER_H_
