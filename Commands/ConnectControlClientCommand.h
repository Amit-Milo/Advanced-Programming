//
// Created by amit on 24/12/2019.
//

#ifndef EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
#define EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_

#include <arpa/inet.h>
#include <string>
#include <thread>
#include <vector>

#include "../Containers/Container.h"
#include "Command.h"


class ConnectControlClientCommand : public Command{
  /**
   * A function used by a thread to try to connect to the simulator as a client.
   * @param container contains important information of the program.
   */
  void ConnectToServer(Container *container);

 public:
  /**
   * Execute the command. Try to connect to the simulator as a client.
   * @param params a vector of parameters used by the command.
   * @param start index implying where to start reading from the vector.
   * @return how many jumps should be taken.
   */
  int execute(vector<string>& params, int start);

  /**
   * A constructor.
   * @param container contains important information of the program.
   */
  ConnectControlClientCommand(Container *container) :Command(container){}
};

#endif //EX3_COMMANDS_CONNECTCONTROLCLIENTCOMMAND_H_
