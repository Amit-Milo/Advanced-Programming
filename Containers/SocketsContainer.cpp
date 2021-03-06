//
// Created by amit on 23/12/2019.
//

#include <iostream>
#include <unistd.h>
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

  // Send data to the server.
  send(this->client_socket, data.c_str(), data.length(), 0);
}


void SocketsContainer::ReleaseSockets() {
  // Shut down both sockets, both for read and write.
  shutdown(this->server_socket, SHUT_RD);
  shutdown(this->client_socket, SHUT_RD);

  shutdown(this->server_socket, SHUT_WR);
  shutdown(this->client_socket, SHUT_WR);

  // CLose the sockets.
  close(this->server_socket);
  close(this->client_socket);
}
