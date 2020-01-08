//
// Created by amit on 23/12/2019.
//

#include <iostream>
#include "SocketsContainer.h"
SocketsContainer::SocketsContainer() {
  // Create an instance of the sockets.
  this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
  this->client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Equivalent to check (server_socket == -1) or (client_socket == -1)
  if (!(server_socket + 1) * (client_socket + 1))
    throw "Couldn't allocate socket.";
}


void SocketsContainer::SendToServer(string data) {
  while (!this->clientConnected) {}

  cout << "Told me connected" << endl;

  // Send data to the server.
  int is_sent = send(this->client_socket, data.c_str(), data.length(), 0);
  cout << "sent? ";
  cout << is_sent << endl;
}
