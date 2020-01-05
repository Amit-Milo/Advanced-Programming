//
// Created by amit on 24/12/2019.
//

#include "OpenDataServerCommand.h"

#include "../StringOperations.h"
#include "../InterpreterFiles/Interpreter.h"

// execute of this class needs only 1 param.
#define RETURN_VALUE 2

int OpenDataServerCommand::execute(vector<string> &params, int start) {
  // Address family.
  container->sockets.server_address.sin_family = AF_INET;

  // Equivalent to 0.0.0.0
  container->sockets.server_address.sin_addr.s_addr = INADDR_ANY;

  // Set port to listen on.
  container->sockets.server_address.sin_port = htons(container->interpreter->evaluate(params[start+1]));

  // Try to bind server.
  if (bind(container->sockets.server_socket,
           (struct sockaddr *) &(container->sockets.server_address),
           sizeof(container->sockets.server_address)) != -1) {

    // Run server in a new thread.
    thread(&OpenDataServerCommand::run_server, this, container).detach();

    // We succeeded communicating with the simulator.
    container->serverConnected = true;

    // Return the expected return value.
    return RETURN_VALUE;
  } else {
    throw "Couldn't bind server.";
  }
}
void OpenDataServerCommand::run_server(Container *container) {
  // A buffer for reading data sent from the simulator.
  char *buffer = (char *) malloc(sizeof(char) * this->maxSize);

  // Receive the amount of data sent by the simulator.
  int dataSize;

  // A vector of values of vars.
  float *values = (float *) malloc(sizeof(float) * this->simVarsAmount);

  // A reminder from the last time the simulator sent a message.
  char *reminder = (char *) malloc(sizeof(char) * this->maxSize);

  // A concat of reminder and buffer;
  char *result;

  // The next index to assign value to next time.
  int firstValue = 0;

  // Rename some vars.
  int server_socket = container->sockets.server_socket;
  sockaddr_in server_address = container->sockets.server_address;


    if (listen(server_socket, 1) == -1)
      // If can't listen, throw an error.
      throw "Couldn't listen.";

    // Accept the client.
    int client_socket = accept(server_socket, (struct sockaddr *) &server_address, (socklen_t *) &server_address);

    if (client_socket != -1)
      // If can't accept a client, throw an error.
      throw "Couldn't accept a client.";

  while (true) {
    // Receive data from the simulator.
    dataSize = read(client_socket, buffer, maxSize);

    if (dataSize < 1)
      // If didn't read nothing, continue to next iteration.
      continue;

    // Concat the given data with the reminder from previous iteration.
    result = strcat(reminder, buffer);

    // Get next index to read from.
    int nextStart = splitValues(result, ",", values);

    // Move to the next index to read from.
    reminder = result + nextStart;

    // Get the amount of values which have been read.
    int valuesLength = sizeof(values) / sizeof(*values);

    for (int i = firstValue; i - firstValue < valuesLength; ++i)
      // Write each variable to the map.
      this->container->maps->WriteWrappedVar(this->container->maps->names[i], values[i]);

    if (result[nextStart - 1] == '\n')
      // Check if we reached to the end of a message sent by the simulator.
      firstValue = 0;
    else
      // Else, increment the next index of value by the amount of values read.
      firstValue += valuesLength;
  }

  // Free the dynamically allocated arrays.
  free(reminder);
  free(values);
  free(buffer);
}

