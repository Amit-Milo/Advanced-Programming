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

    // Run server in a new thread.
    thread(&OpenDataServerCommand::run_server, this, &container).detach();

    // TODO Set a temporarily blocking variable.

    // Return the expected return value.
    return RETURN_VALUE;
  }
  else {
    throw "Couldn't bind server.";
  }
}
void OpenDataServerCommand::run_server(Container* container) {
  // A buffer for reading data sent from the simulator.
  char *buffer = (char *)malloc(sizeof(char) * this->maxSize);

  // Receive the amount of data sent by the simulator.
  int dataSize;

  // A vector of values of vars.
  float *values = (float *)malloc(sizeof(float) * this->simVarsAmount);

  int server_socket = container->sockets.server_socket;
  sockaddr_in server_address = container->sockets.server_address;

  while (true) {
    if(listen(server_socket, 1) == -1)
      continue;

    int client_socket = accept(server_socket, (struct sockaddr*) &server_address, (socklen_t*) &server_address);

    if (client_socket == -1)
      continue;

    dataSize = read(client_socket, buffer, maxSize);

    if (dataSize < 1)
      continue;

    // TODO split(buffer, values)
    // TODO for value in values write(map, value)
  }

  free(values);
  free(buffer);
}
