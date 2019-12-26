//
// Created by amit on 24/12/2019.
//

// execute of this class needs 2 params.
#define RETURN_VALUE 3

#include "ConnectControlClientCommand.h"

int ConnectControlClientCommand::execute(vector<string>& params, int start, Container& container) {

  // Address family.
  container.sockets.client_address.sin_family = AF_INET;

  // Set address as given by the parameters.
  container.sockets.client_address.sin_addr.s_addr = inet_addr(params[start].c_str());

  // Set port as given by the parameters.
  container.sockets.client_address.sin_port = htons(stoi(params[start + 1]));

  if (!connect(container.sockets.client_socket, (struct sockaddr*) &container.sockets.client_address, sizeof(container.sockets.client_address)))
    return RETURN_VALUE;
  else
    throw "Couldn't connect to server.";
}
