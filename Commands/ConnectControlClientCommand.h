//
// Created by amit on 24/12/2019.
//

#ifndef EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
#define EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_

#include <arpa/inet.h>
#include <string>
#include <vector>

#include "Command.h"

class ConnectControlClientCommand : public Command {
 public:
  int execute(vector<string> &params, int start, Container &container);
};

#endif //EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
