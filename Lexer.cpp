//
// Created by yoav on 21/12/2019.
//

#include <iostream>
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
  //else, handle the command:


  //first, handle special commands: OpenDataServer and ConnectControlClient:
  if (startsWith(s, OPEN_DATA_SERVER)) {
    commands->push_back(string(OPEN_DATA_SERVER));
    int openBracesIndex = s.find("(");
    int closeBracesIndex = s.rfind(")");
    commands->push_back(noSpaces(s.substr(openBracesIndex + 1, closeBracesIndex - openBracesIndex - 1)));
  } else if (startsWith(s, CONNECT_CONTROL_CLIENT)) {
    commands->push_back(string(CONNECT_CONTROL_CLIENT));
    int openBracesIndex = s.find("(");
    int twoArgsSeperate = s.rfind(",");
    int closeBracesIndex = s.rfind(")");
    commands->push_back(noSpaces(s.substr(openBracesIndex + 1, twoArgsSeperate - openBracesIndex - 1)));
    commands->push_back(noSpaces(s.substr(twoArgsSeperate + 1, closeBracesIndex - twoArgsSeperate - 1)));
  }
    //now the rest:
  else if (s.find("\"") != string::npos) { //add the string of the quotes
    int begin = s.find("\"");
    int end = s.find("\"", begin + 1);
    if (end == string::npos) {
      throw "illegal quotes";
    }
    this->addCommands(s.substr(0, begin), commands);
    commands->push_back(s.substr(begin, end - begin + 1));
    this->addCommands(s.substr(end + 1), commands);
  } else if (handleArrow(s, commands)) {
    return;
  } else if (handleCondition(s, commands)) {
    return;
  } else if (s.find("=") != string::npos) { //add everything after the equal sign with no spaces
    this->addCommands(s.substr(0, s.find("=")), commands);
    commands->push_back("=");
    //now handle the rest of the line:
    commands->push_back(noSpaces(s.substr(s.find("=") + 1)));
  } else if (s.find(" ") != string::npos) { //seperate
    handleSpecialSubstr(s, " ", commands, false);
  } else if (s.find("\t") != string::npos) { //useless indentation
    handleSpecialSubstr(s, "\t", commands, false);
  } else if (s.find("(") != string::npos) {
    handleSpecialSubstr(s, "(", commands, false);
  } else if (s.find(")") != string::npos) {
    handleSpecialSubstr(s, ")", commands, false);
  } else if (s.find(",") != string::npos) {
    handleSpecialSubstr(s, ",", commands, false);
  } else if (s.find("{") != string::npos) {
    handleSpecialSubstr(s, "{", commands, true);
  } else if (s.find("}") != string::npos) {
    handleSpecialSubstr(s, "}", commands, true);
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
string Lexer::noSpaces(string s) {
  string result("");
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) != ' ') {
      result.append(1, s.at(i));
    }
  }
  return result;
}
bool Lexer::startsWith(string s, string start) {
  return caseInsensitiveMatch(s.substr(0, start.length()), start);
}

bool Lexer::caseInsensitiveMatch(string s1, string s2) {
  //convert s1 and s2 into lower case strings
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  return s1.compare(s2) == 0;
}

bool Lexer::handleCondition(string s, vector<string> *commands) {
  //check if first word is "while" or "if"
  string firstWord("");
  if (startsWith(s, "if ")) {
    firstWord = "if";
  } else if (startsWith(s, "while ")) {
    firstWord = "while";
  }
  if (firstWord.compare("") == 0) {
    return false;
  }
  commands->push_back(firstWord);

  string condition("");
  if (s.find("!=") != string::npos) {
    condition = "!=";
  } else if (s.find("==") != string::npos) {
    condition = "==";
  } else if (s.find("<=") != string::npos) {
    condition = "<=";
  } else if (s.find(">=") != string::npos) {
    condition = ">=";
  } else if (s.find(">") != string::npos) {
    condition = ">";
  } else if (s.find("<") != string::npos) {
    condition = "<";
  }
  if (condition.compare("") == 0) {
    throw "error, line starts with while/if but no condition sign";
  }
  commands->push_back(noSpaces(s.substr(firstWord.length(), s.find(condition) - firstWord.length())));
  commands->push_back(condition);
  commands->push_back(noSpaces(s.substr(s.find(condition) + condition.length(),
                                        s.find("{") - (s.find(condition) + condition.length()))));
  commands->push_back(string("{"));

  return true;
}

bool Lexer::handleArrow(string s, vector<string> *commands) {
  string arrow("");
  if (s.find("<-") != string::npos) {
    arrow = "<-";
  } else if (s.find("->") != string::npos) {
    arrow = "->";
  }
  if (arrow.compare("") != 0) {
    handleSpecialSubstr(s, arrow, commands, true);
    return true;
  }
  return false;
}

