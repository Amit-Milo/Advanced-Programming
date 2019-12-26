//
// Created by yoav on 21/12/2019.
//

#ifndef EX3__LEXER_H_
#define EX3__LEXER_H_

#define CONNECT_CONTROL_CLIENT "ConnectControlClient"
#define OPEN_DATA_SERVER "OpenDataServer"

#include <string>
#include <vector>
#include <fstream>
#include "InterpreterFiles/VarsSetter.h"

using namespace std;
class Lexer {
 public:
  vector<string> *lexer(string filename);
  void addCommands(string s, vector<string> *commands);
  void handleSpecialSubstr(string s, string special, vector<string> *commands, bool shouldAddSpecial);
  string noSpaces(string s);
  bool startsWith(string s, string start);
  bool caseInsensitiveMatch(string s1, string s2);

  bool handleCondition(string s, vector<string> *commands);
  bool handleArrow(string s, vector<string> *commands);
};

#endif //EX3__LEXER_H_
