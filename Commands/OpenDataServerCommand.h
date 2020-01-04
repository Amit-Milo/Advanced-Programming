//
// Created by amit on 24/12/2019.
//

#ifndef EX3__OPENDATASERVERCOMMAND_H_
#define EX3__OPENDATASERVERCOMMAND_H_

#include <math.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

#include "../Containers/Container.h"
#include "../Containers/MapsContainer.h"

#include "Command.h"

//TODO amit comments

using namespace std;

class OpenDataServerCommand : public Command {

  // A constant used in calculating the max size to read from the simulator.
  const int digitsOfFloat = (int) (1 + log(pow(2, 8 * sizeof(float))));

  // How many simulator vars are there.
  int simVarsAmount;

  // Need to know maximum size to read from the simulator.
  int maxSize;

  void run_server(Container *container);

 public:
  OpenDataServerCommand(Container *container, int sim_vars_amount)
      : Command(container), simVarsAmount(sim_vars_amount) {
    this->maxSize = this->simVarsAmount * this->maxSize + this->simVarsAmount + 1;

  }

  int execute(vector<string> &params, int start);
};

#endif //EX3__OPENDATASERVERCOMMAND_H_
