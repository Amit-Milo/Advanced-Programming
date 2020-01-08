//
// Created by yoav on 17/11/2019.
//

#ifndef EX1__CALCULATIONTOKENSCREATORCHECKER_H_
#define EX1__CALCULATIONTOKENSCREATORCHECKER_H_

#include <string>
#include <map>
#include <list>
#include <iostream>
#include <stack>
#include <regex>
#include "../Expressions/Expression.h"
#include "../Containers/Container.h"

#define BRACE 1
#define OPERATOR 2
#define NUMBER 3
#define VARIABLE 4
#define OPEN_BRACE_TO_STACK 10

class CalculationTokensCreatorChecker {
 public:
  //main
  list<pair<string, int>> *createTokensList(string s, Container *container);
  //split string to list
  /**
    * splits the string to tokens for the SY algo. if found unary expression = plus/minus sign after opening braces,
    * insert 0 between the brace and the operator to make it binary
    * @param s
    * @param tokens
    */
  void tokensSplitter(string s, list<pair<string, int>> *tokens);
  bool isOperator(string s);
  bool isUnaryStart(string s);
  bool isBraces(string s);
  bool isNumber(string s);
  //check valid list
  /**
    * check if tokens are valid
    * @param tokens
    * @param variables
    * @return true if the tokens are valid, false otherwise.
    */
  bool checkValidTokens(list<pair<string, int>> *tokens, Container *container);
  /**
   * @return if number ob opening braces equals number of closing braces
   */
  bool checkBraces(list<pair<string, int>> *tokens);
  bool checkAdjOperators(list<pair<string, int>> *tokens);
  bool checkValidVars(list<pair<string, int>> *tokens, Container *container);
  bool checkNoOperatorsInEnds(list<pair<string, int>> *tokens);
};

#endif //EX1__CALCULATIONTOKENSCREATORCHECKER_H_
