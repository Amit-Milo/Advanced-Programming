//
// Created by amit on 24/12/2019.
//

#ifndef EX3__OPENDATASERVERCOMMAND_H_
#define EX3__OPENDATASERVERCOMMAND_H_

#include <cstring>
#include <math.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

#include "../Containers/Container.h"
#include "../Containers/MapsContainer.h"

#include "Command.h"

using namespace std;

class OpenDataServerCommand : public Command {

  // A constant used in calculating the max size to read from the simulator.
  const int digitsOfFloat = (int) (1 + log(pow(2, 8 * sizeof(float))));

  // How many simulator vars are there.
  int simVarsAmount;

  // Need to know maximum size to read from the simulator.
  int maxSize;

  /**
   * A function called by a thread to run as server at the background.
   * @param container a container which contains all the necessary information.
   */
  void run_server(Container *container);

 public:
  /**
   * A constructor for the command.
   * Set the value of important fields.
   * @param container  container which contains all the necessary information.
   * @param sim_vars_amount the maximum amount of variables sent by the simulator.
   */
  OpenDataServerCommand(Container *container_, int sim_vars_amount)
      : Command(container_), simVarsAmount(sim_vars_amount) {
    /*
     * Each variables needs at most the maximum digits which float needs.
     * In addition, to each variable there attached a space or a \n char.
     * We need a place for the \0 char.
     */
    this->maxSize = this->simVarsAmount * this->digitsOfFloat + this->simVarsAmount + 1;

  }

  /**
   * Execute the command. Open a server and run it at the background.
   * @param params a vector of string contains the parameters  to the command.
   * @param start the index of the first parameter to use.
   * @return how many jumps should be taken.
   */
  int execute(vector<string> &params, int start);
};

#endif //EX3__OPENDATASERVERCOMMAND_H_
