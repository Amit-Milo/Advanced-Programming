//
// Created by amit on 24/12/2019.
//

// execute of this class needs 2 params.
#define RETURN_VALUE 3

#include "ConnectControlClientCommand.h"
#include "../InterpreterFiles/Interpreter.h"

int ConnectControlClientCommand::execute(vector<string> &params, int start) {

  // Address family.
  container->sockets.client_address.sin_family = AF_INET;

  // Set address as given by the parameters.
  container->sockets.client_address.sin_addr.s_addr = inet_addr((params[start + 1].substr(1, params[start + 1].length() - 2)).c_str());

  // Set port as given by the parameters.
  container->sockets.client_address.sin_port = htons(container->interpreter->evaluate(params[start + 2]));

  // Run a thread trying to connect as client to the simulator.
  thread(&ConnectControlClientCommand::ConnectToServer, this, container).detach();

  //  Return how many jumps should be taken.
  return RETURN_VALUE;
}

void ConnectControlClientCommand::ConnectToServer(Container *container) {
  while (!container->serverConnected)
    // Wait until getting alerted that the simulator connected to the server - implying that the simulator is running.
    continue;

  if (!(connect(container->sockets.client_socket,
                (struct sockaddr *) &(container->sockets.client_address),
                sizeof(container->sockets.client_address)) + 1))
    // Try to connect to the simulator as client. If failed throw an error.
    throw "Couldn't connect to server.";
}
