//
// Created by amit on 24/12/2019.
//

#ifndef EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
#define EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_

#include <arpa/inet.h>
#include <string>
#include <vector>

#include "../Containers/Container.h"

class ConnectControlClientCommand {
 public:
  int execute(vector<string>& params, int start, Container& container);
};

#endif //EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
