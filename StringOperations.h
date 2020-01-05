//
// Created by amit on 03/01/2020.
//

#ifndef EX3__STRINGOPERATIONS_H_
#define EX3__STRINGOPERATIONS_H_

#include <string>

using namespace std;


/**
 * Split a string of values to an array to contain this values.
 * @param data the string of the values (separated by ',').
 * @param delimiter a char used to indicate where to split the values (should be ',').
 * @param target the array to move the values to.
 * @return next position to read from if not split the whole text (i.e. found a '\n' in the text),
 * or the end of the string if read the whole data.
 */
int splitValues(string data, string delimiter, float target[]);

#endif //EX3__STRINGOPERATIONS_H_
