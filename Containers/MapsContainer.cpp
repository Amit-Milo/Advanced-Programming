//
// Created by amit on 01/01/2020.
//

#include "MapsContainer.h"


SimulatorVar *MapsContainer::ReadVar(string key) {
  // We want to prevent only writers from changing our map. Readers are accepted.
  this->writers_lock.lock();

  SimulatorVar *returnValue = this->vars[key];

  this->writers_lock.unlock();
  return returnValue;
}

void MapsContainer::WriteVar(string key, double value) {
  // Nobody should access the map when we edit it.
  this->readers_lock.lock();
  this->writers_lock.lock();

  this->vars[key].SetValue(value);

  this->writers_lock.unlock();
  this->readers_lock.unlock();
}


bool MapsContainer::InVars(string index) {
  // We want to prevent only writers from changing our map. Readers are accepted.
  this->writers_lock.lock();

  bool inVars = this->vars.count(index);

  this->writers_lock.unlock();
  return inVars;
}
