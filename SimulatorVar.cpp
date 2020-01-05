//
// Created by yoav on 22/12/2019.
//

#include "SimulatorVar.h"

#include "Containers/MapsContainer.h"

SimulatorVar::SimulatorVar(const string &prog_name, const string &simulator_name, Wrapping wrapping, Container *container) : progName(
    prog_name), simulatorName(simulator_name), wrapping(wrapping), container(container) {
  if (wrapping == SIM_TO_PROG)
    container->maps->AddWrappedVar(simulator_name, progName);
}

SimulatorVar::SimulatorVar(double value, const string &prog_name, Container *container) : value(value), progName(prog_name) {
  wrapping = NONE;
}
double SimulatorVar::GetValue() const {
  return value;
}
void SimulatorVar::SetValue(double value) {
  this->value = value;

  if (SimulatorVar::wrapping == PROG_TO_SIM) {
    //change the sim var too.
    thread(&SimulatorVar::WriteToSimulator, this, simulatorName, value).detach();
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

void SimulatorVar::WriteToSimulator(string name, float value) {
  // Format a message to send to the simulator.
  string message("set " + name + " " + to_string(value) + "\n");
  cout<<message<<endl;
  this->container->sockets.SendToServer(message);
}