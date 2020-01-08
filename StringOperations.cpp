//
// Created by amit on 03/01/2020.
//

#include <iostream>
#include "StringOperations.h"


// Split a string using a delimiter.
int splitValues(string data, string delimiter, float target[]) {
  size_t pos;
  string token;
  int i = 0;

  cout << "data: " + data << endl;


  // Find next position of the delimiter.
  while ((pos = data.find(delimiter)) != string::npos && pos < data.find('\n')) {
    // Get the substring bounded by the delimiter.
    token = data.substr(0, pos);

    cout << "token: " + token << endl;

    // Add the token to the target array.
    target[i] = stof(token);

    // Remove (locally) the already used data.
    data.erase(0, pos + delimiter.length());

    ++i;
  }

  // Last substring may appear at the end of the string.
  if (data.length() > 0 && pos < data.find('\n')) {
    token = data.substr(0, pos);
    target[i] = stof(token);
  }

  return pos;

}