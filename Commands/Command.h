//
// Created by yoav on 21/12/2019.
//

#ifndef EX3_COMMANDS_COMMAND_H_
#define EX3_COMMANDS_COMMAND_H_

#include <vector>
#include <string>

using namespace std;

class Container;

class Command {
 protected:
  Container *container;
 public:
  /**
   * the calling to command's execution.
   * @param params the vector of strings
   * @param start the index of first string in this command
   * @return number to jump in the vector
   */
  virtual int execute(vector<string> &params, int start) = 0;
  Command(Container *container) : container(container) {}
};

#endif //EX3_COMMANDS_COMMAND_H_
