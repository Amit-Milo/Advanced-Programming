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

#define BRACE 1
#define OPERATOR 2
#define NUMBER 3
#define VARIABLE 4
#define OPEN_BRACE_TO_STACK 10

class CalculationTokensCreatorChecker{
 public:
  //main
  list<pair<string, int>>* createTokensList(string s, map<string, double> *variables);
  //split string to list
  void tokensSplitter(string s, list<pair<string, int>>* tokens);
  bool isOperator(string s);
  bool isUnaryStart(string s);
  bool isBraces(string s);
  bool isNumber(string s);
  void printTokensList(list<pair<string,int>>* l);
  //check valid list
  bool checkValidTokens(list<pair<string, int>>* tokens, map<string, double> *variables);
  bool checkBraces(list<pair<string, int>>* tokens);
  bool checkAdjOperators(list<pair<string, int>>* tokens);
  bool checkValidVars(list<pair<string, int>>* tokens, map<string, double> *variables);
  bool checkNoOperatorsInEnds(list<pair<string,int>>* tokens);
};

#endif //EX1__CALCULATIONTOKENSCREATORCHECKER_H_
