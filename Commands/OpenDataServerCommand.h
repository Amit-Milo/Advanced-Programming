//
// Created by amit on 24/12/2019.
//

#ifndef EX3__OPENDATASERVERCOMMAND_H_
#define EX3__OPENDATASERVERCOMMAND_H_

#include <netinet/in.h>
#include <string>
#include <thread>
#include <vector>

#include "../Containers/Container.h"
#include "Command.h"

using namespace std;

class OpenDataServerCommand: public Command {
  static void run_server(Container& container);

 public:
  int execute(vector<string>& params, int start, Container& container);
};

#endif //EX3__OPENDATASERVERCOMMAND_H_
