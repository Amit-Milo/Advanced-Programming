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
#include "../Expressions/Expression.h"
#include "CalculationTokensCreatorChecker.h"

#include "../Expressions/Value.h"
#include "../Expressions/BinOperators/Mul.h"
#include "../Expressions/BinOperators/Div.h"
#include "../Expressions/BinOperators/Plus.h"
#include "../Expressions/BinOperators/Minus.h"
#include "../Expressions/Variable.h"

class TokensToExpressionConverter {
 public:
  Expression *tokensToExpression(list<pair<string, int>> *tokens, Container* container);
  stack<pair<string,int>>* tokensToStack(list<pair<string, int>> *tokens);
  Expression *stackToExpression(stack<pair<string,int>>* calcStack, Container* container);
  int compareOperators(string s1, string s2);
  void printStack(stack<pair<string,int>>* s);
};

#endif //EX1__TOKENSTOEXPRESSIONCONVERTER_H_
