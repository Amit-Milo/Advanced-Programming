//
// Created by yoav on 21/12/2019.
//

#include "Lexer.h"

vector<string> *Lexer::lexer(string fileName) {
  ifstream f;
  f.open(fileName);
  if (!f.is_open()) {
    throw "could not open file";
  }
  vector<string> *commands = new vector<string>;
  VarsSetter vs;
  /////////////////////////////////
  string line;
  while (getline(f, line)) {
    addCommands(line, commands);
  }
  /////////////////////////////////
  f.close();
  return commands;
}

void Lexer::addCommands(string s, vector<string> *commands) {
  if (s.length() == 0) {
    return;
  }
  //else, handle the command
  if (s.find(" ") != string::npos) { //seperate
    handleSpecialSubstr(s, " ", commands, false);
  } else if (s.find("\t") != string::npos) { //useless indentation
    handleSpecialSubstr(s, "\t", commands, false);
  } else if (s.find("!=") != string::npos) { //condition
    handleSpecialSubstr(s, "!=", commands, true);
  } else if (s.find("==") != string::npos) { //condition
    handleSpecialSubstr(s, "==", commands, true);
  } else if (s.find("<=") != string::npos) { //condition
    handleSpecialSubstr(s, "<=", commands, true);
  } else if (s.find(">=") != string::npos) { //condition
    handleSpecialSubstr(s, ">=", commands, true);
  } else if (s.find("<-") != string::npos) { //wrap
    handleSpecialSubstr(s, "<-", commands, true);
  } else if (s.find("->") != string::npos) { //wrap
    handleSpecialSubstr(s, "->", commands, true);
  } else if (s.find(">") != string::npos) { //condition
    handleSpecialSubstr(s, ">", commands, true);
  } else if (s.find("<") != string::npos) { //condition
    handleSpecialSubstr(s, "<", commands, true);
  } else if (s.find("(") != string::npos) {
    handleSpecialSubstr(s, "(", commands, true);
  } else if (s.find(")") != string::npos) {
    handleSpecialSubstr(s, ")", commands, true);
  } else if (s.find(",") != string::npos) {
    handleSpecialSubstr(s, ",", commands, false);
  } else {
    commands->push_back(s);
  }
}

void Lexer::handleSpecialSubstr(string s, string special, vector<string> *commands, bool shouldAddSpecial) {
  this->addCommands(s.substr(0, s.find(special)), commands);
  if (shouldAddSpecial) {
    commands->push_back(special);
  }
  this->addCommands(s.substr(s.find(special) + special.length(), s.length() - (s.find(special) + special.length())),
                    commands);
}



