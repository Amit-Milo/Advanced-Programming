//
// Created by yoav on 17/11/2019.
//

#include "CalculationTokensCreatorChecker.h"

#include "../Containers/MapsContainer.h"

bool CalculationTokensCreatorChecker::isOperator(string s) {
  if (s.length() > 1) {
    return false;
  }
  return s.compare("+") == 0 || s.compare("-") == 0 || s.compare("/") == 0 || s.compare("*") == 0;
}
bool CalculationTokensCreatorChecker::isUnaryStart(string s) {
  if (s.length() > 1) {
    return false;
  }
  return s.compare("+") == 0 || s.compare("-") == 0;
}
bool CalculationTokensCreatorChecker::isBraces(string s) {
  if (s.length() > 1) {
    return false;
  }
  return s.compare(")") == 0 || s.compare("(") == 0;
}
bool CalculationTokensCreatorChecker::isNumber(string s) {
  regex number("[\\d]+(\\.[\\d]+)?");
  return regex_match(s, number);
}

list<pair<string, int>> *CalculationTokensCreatorChecker::createTokensList(string s, Container *container) {
  list<pair<string, int>> *tokens = new list<pair<string, int>>;
  tokensSplitter(s, tokens);
  if (!checkValidTokens(tokens, container)) {
    throw "illegal calculation line";
  }
  return tokens;
}


void CalculationTokensCreatorChecker::tokensSplitter(string s, list<pair<string, int>> *tokens) {
  int i = 0;
  if (isUnaryStart(string(1, s.at(0)))) {
    tokens->push_back(pair<string, int>("0", NUMBER));
  }
  string prev = "0";
  int sLength = (int) s.length();
  while (i < sLength) {
    string c = string(1, s.at(i));
    if (isOperator(c)) {
      //if this is a start of an unary expression, insert 0 before.
      if (isUnaryStart(c) && prev.compare("(") == 0) {
        tokens->push_back(pair<string, int>("0", NUMBER));
      }
      tokens->push_back(pair<string, int>(c, OPERATOR));
      prev = c;
      i++;
    } else if (isBraces(c)) {
      tokens->push_back(pair<string, int>(c, BRACE));
      i++;
      prev = c;
    } else {
      //it is a number/letter/underscore
      int start = i;
      while (i < sLength && !isBraces(string(1, s.at(i))) && !isOperator(string(1, s.at(i)))) {
        //continue reading the string until hitting a sign that ends the var/number
        i++;
      }
      string token = s.substr(start, i - start);
      if (isNumber(token)) {
        tokens->push_back(pair<string, int>(s.substr(start, i - start), NUMBER));
      } else {
        tokens->push_back(pair<string, int>(s.substr(start, i - start), VARIABLE));
      }
      prev = token;
    }
    //the i++ is already in each condition statement
  }
}


bool CalculationTokensCreatorChecker::checkValidTokens(list<pair<string, int>> *tokens,
                                                       Container *container) {
  return checkBraces(tokens) && checkAdjOperators(tokens) && checkValidVars(tokens, container)
      && checkNoOperatorsInEnds(tokens);
}

bool CalculationTokensCreatorChecker::checkBraces(list<pair<string, int>> *tokens) {
  stack<int> checker;
  for (const auto &myPair : *tokens) {
    if (myPair.first.compare("(") == 0) {
      checker.push(OPEN_BRACE_TO_STACK);
    } else if (myPair.first.compare(")") == 0) {
      if (checker.empty()) {
        throw "illegal braces alignment";
      }
      checker.pop();
    }
  }
  if (!checker.empty()) {
    throw "illegal braces alignment";
  }
  return true;
}

bool CalculationTokensCreatorChecker::checkAdjOperators(list<pair<string, int>> *tokens) {
  pair<string, int> prev("", -1);
  for (const auto &myPair : *tokens) {
    if (myPair.second == OPERATOR && prev.second == OPERATOR) {
      throw "illegal sequence, should not have 2 adjacent operators";
    }
    prev = myPair;
  }
  return true;
}

bool CalculationTokensCreatorChecker::checkValidVars(list<pair<string, int>> *tokens, Container *container) {
  for (const auto &myPair : *tokens) {
    if (myPair.second == VARIABLE) {
      if (container->maps->vars.count(myPair.first) == 0) {
        throw "illegal calculation: var name is illegal or unset";
      }
    }
  }
  return true;
}
bool CalculationTokensCreatorChecker::checkNoOperatorsInEnds(list<pair<string, int>> *tokens) {
  return tokens->front().second != OPERATOR && tokens->back().second != OPERATOR;
}
