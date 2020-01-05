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
#include "../Containers/Container.h"
#include "../Containers/MapsContainer.h"

class TokensToExpressionConverter {
 public:
  /**
   * convert the tokens list to an expression using tokensToStack and stackToExpression
   */
  Expression *tokensToExpression(list<pair<string, int>> *tokens, Container* container);
  /**
   * move the tokens list to tokens stack
   */
  stack<pair<string,int>>* tokensToStack(list<pair<string, int>> *tokens);
  /**
   * convert the stack of tokens to an Expression Object
   */
  Expression *stackToExpression(stack<pair<string,int>>* calcStack, Container* container);
  /**
   * compare which operator is stronger
   */
  int compareOperators(string s1, string s2);
};


#endif //EX1__TOKENSTOEXPRESSIONCONVERTER_H_
