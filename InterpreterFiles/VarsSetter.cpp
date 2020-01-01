//
// Created by yoav on 17/11/2019.
//

#include "VarsSetter.h"

void VarsSetter::setVariables(string s, map<string, double> *variables) {
  if (!checkValidVars(s)) {
    throw "invalid variables list";
  }
  if (s.at(s.length() - 1) == ';') {
    s = s.substr(0, s.length() - 1);
  }
  if (findNextChar(s, ';', INDEX_FOR_STRING_START_SEARCH) == -1) { //there is only one var
    addNewVar(s, variables);
  } else {
    int prevIndex = INDEX_FOR_STRING_START_SEARCH;
    int index = findNextChar(s, ';', INDEX_FOR_STRING_START_SEARCH);
    while (index != -1) {
      addNewVar(s.substr(prevIndex + 1, index - prevIndex - 1), variables);
      prevIndex = index;
      index = findNextChar(s, ';', index);
    }
    addNewVar(s.substr(prevIndex + 1, s.length() - prevIndex - 1), variables);
  }
}
bool VarsSetter::checkValidVars(string s) {
  regex p("([_a-zA-Z][\\w]*=\\-?[\\d]+(\\.[\\d]+)?)(;([_a-zA-Z][\\w]*=\\-?[\\d]+(\\.[\\d]+)?))*;?");
  return regex_match(s, p);
}

/**
 * @param s the string to search c in
 * @param c the char to search
 * @param startIndex the first index to search from
 * @return the first index starting at startIndex that matches c. if no match, return -1.
 */
int VarsSetter::findNextChar(string s, char c, int startIndex) {
  int index = startIndex + 1;
  int sLength = (int) s.length();
  while (index < sLength) {
    if (s.at(index) == c) {
      return index;
    }
    index++;
  }
  return -1;
}

void VarsSetter::addNewVar(string varDef, map<string, double> *variables) {
  int equalSignIndex = findNextChar(varDef, '=', 0);
  string varName = varDef.substr(0, equalSignIndex);
  double varValue = stod(varDef.substr(equalSignIndex + 1, varDef.length()));

  if (variables->count(varName) == 1) {
    variables->at(varName) = varValue;
  }
  variables->insert(pair<string, double>(varName, varValue));
}