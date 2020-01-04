//
// Created by amit on 03/01/2020.
//

#include "StringOperations.h"
// Split a string using a delimiter.
void splitValues(string data, string delimiter, float target[]) {
  size_t pos;
  string token;
  int i = 0;

  // Find next position of the delimiter.
  while ((pos = data.find(delimiter)) != string::npos) {
    // Get the substring bounded by the delimiter.
    token = data.substr(0, pos);

    // Add the token to the target array.
    target[i] = stof(token);

    // Remove (locally) the already used data.
    data.erase(0, pos + delimiter.length());

    ++i;
  }

  // Last substring may appear at the end of the string.
  if (data.length() > 0) {
    token = data.substr(0, pos);
    target[i] = stof(token);
  }
}