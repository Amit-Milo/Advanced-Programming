//
// Created by yoav on 17/11/2019.
//


#ifndef EX1__VARSSETTER_H_
#define EX1__VARSSETTER_H_

#include <string>
#include <map>
#include <regex>
#include "../Expressions/Expression.h"

#define INDEX_FOR_STRING_START_SEARCH (-1)

class VarsSetter {
 public:
  void setVariables(string s, map<string, double> *variables);
  bool checkValidVars(string s);
  int findNextChar(string s, char c, int startIndex);
  void addNewVar(string varDef, map<string, double> *variables);
};

#endif //EX1__VARSSETTER_H_
