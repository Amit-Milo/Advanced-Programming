//
// Created by yoav on 21/12/2019.
//

#ifndef EX3__LEXER_H_
#define EX3__LEXER_H_

#define LEXER_SEPERATE_CHAR ' '

#include <string>
#include <vector>
#include <fstream>
#include "InterpreterFiles/VarsSetter.h"

using namespace std;
class Lexer{
 public:
  vector<string>* lexer(string filename);
  void addCommands(string s, vector<string>* commands);
  void handleSpecialSubstr(string s, string special, vector<string>* commands, bool shouldAddSpecial);
};

#endif //EX3__LEXER_H_
