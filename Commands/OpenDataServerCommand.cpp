//
// Created by amit on 24/12/2019.
//

#include "OpenDataServerCommand.h"

// execute of this class needs only 1 param.
#define RETURN_VALUE 2

int OpenDataServerCommand::execute(vector<string>& params, int start, Container& container) {
  // Address family.
  container.sockets.server_address.sin_family = AF_INET;

  // Equivalent to 0.0.0.0
  container.sockets.server_address.sin_addr.s_addr = INADDR_ANY;

  // Set port to listen on.
  container.sockets.server_address.sin_port = htons(stoi(params[start]));

  // Try to bind server.
  if (bind(container.sockets.server_socket, (struct sockaddr*) &container.sockets.server_address, sizeof(container.sockets.server_address)) != -1) {
    thread server(run_server, container);
    server.detach();
    return RETURN_VALUE;
  }
  else {
    throw "Couldn't bind server.";
  }
}
void OpenDataServerCommand::run_server(Container &container) {

}
