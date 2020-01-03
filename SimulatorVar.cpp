//
// Created by yoav on 22/12/2019.
//

#include "SimulatorVar.h"

//constructor for var associated with simulator var
SimulatorVar::SimulatorVar(const string &prog_name, const string &simulator_name, Wrapping wrapping) : progName(
    prog_name), simulatorName(simulator_name), wrapping(wrapping) {
  /////////////////////////////////////////////////////////set the value to the simulator var value
}

//constructor for var not associated with simulator var, the simulatorName field is empty
SimulatorVar::SimulatorVar(double value, const string &prog_name) : value(value), progName(prog_name) {
  wrapping = NONE;
}
double SimulatorVar::GetValue() const {
  return value;
}
void SimulatorVar::SetValue(double value) {
  if (SimulatorVar::wrapping == NONE) {
    SimulatorVar::value = value;
  } else if (SimulatorVar::wrapping == PROG_TO_SIM) {
    SimulatorVar::value = value;
    // TODO also change the var value in the simulator
  } else if (SimulatorVar::wrapping == SIM_TO_PROG) {
    //then the simulator changes the prog var, so just change the value.
    SimulatorVar::value = value;
  } else {
    throw "error with SimulatorVar.SetValue";
  }
}
const string &SimulatorVar::GetProgName() const {
  return progName;
}
void SimulatorVar::SetProgName(const string &prog_name) {
  progName = prog_name;
}
const string &SimulatorVar::GetSimulatorName() const {
  return simulatorName;
}
void SimulatorVar::SetSimulatorName(const string &simulator_name) {
  simulatorName = simulator_name;
}
Wrapping SimulatorVar::GetWrapping() const {
  return wrapping;
}
void SimulatorVar::SetWrapping(Wrapping wrapping) {
  SimulatorVar::wrapping = wrapping;
}




