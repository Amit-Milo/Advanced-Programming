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
#include <algorithm>

using namespace std;
class Lexer {
 public:
  /**
   * the main function.
   * @param filename the file to read from.
   * @return the vector of strings that were in the file, according to the splitting rules.
   */
  vector<string> *lexer(string filename);
  /**
   * handle the adding of a line to the commands vector. works recursively.
   * @param s the string to split and add to the vector.
   * @param commands the vector to add to.
   */
  void addCommands(string s, vector<string> *commands);
  /**
   * input is a special string that should be added. now add its sides recursively.
   * @param s the whole string
   * @param special the special substring
   * @param commands the commands vector
   * @param shouldAddSpecial boolean if the special string should be added to the vector or is just a splitter.
   */
  void handleSpecialSubstr(string s, string special, vector<string> *commands, bool shouldAddSpecial);
  /**
   * @param s a string to remove spaces
   * @return the input string without spaces
   */
  string noSpaces(string s);
  /**
   * @param s a whole string
   * @param start a smaller string
   * @return whether s starts with the string start.
   */
  bool startsWith(string s, string start);
  /**
   * compare the two strings without case sensitivity.
   * @param s1
   * @param s2
   * @return whether the strings are equal without case sensitivity.
   */
  bool caseInsensitiveMatch(string s1, string s2);
  /**
   * handle the adding of a string which is a condition if/while.
   * @param s the whole string.
   * @param commands the commands vector.
   * @return whether the string is indeed a condition command.
   */
  bool handleCondition(string s, vector<string> *commands);
  /**
   * handle the adding of a string which is an arrow declaration.
   * @param s the whole string.
   * @param commands the commands vector.
   * @return whether the string is indeed an arrow declaration.
   */
  bool handleArrow(string s, vector<string> *commands);
};

#endif //EX3__LEXER_H_
