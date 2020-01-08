//
// Created by yoav on 22/12/2019.
//

#include "SimulatorVar.h"
#include "Containers/MapsContainer.h"
#include "Containers/SocketsContainer.h"

SimulatorVar::SimulatorVar(const string &prog_name,
                           const string &simulator_name,
                           Wrapping wrapping_,
                           Container *container_) : progName(
    prog_name), simulatorName(simulator_name), wrapping(wrapping_), container(container_) {
  if (wrapping == SIM_TO_PROG) {
    container->maps->AddWrappedVar(simulator_name, progName);
    this->value = container->maps->ReadSimulatorVar(this->simulatorName);
  }
}
SimulatorVar::SimulatorVar(double value_, const string &prog_name, Container *container_)
    : value(value_), progName(prog_name), container(container_) {
  wrapping = NONE;
}
double SimulatorVar::GetValue() const {
  return value;
}
void SimulatorVar::SetValue(double value_) {
  this->value = value_;

  if (SimulatorVar::wrapping == PROG_TO_SIM) {
    //change the sim var too.
    thread(&SimulatorVar::WriteToSimulator, this, simulatorName, value_).detach();
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
void SimulatorVar::SetWrapping(Wrapping wrapping_) {
  SimulatorVar::wrapping = wrapping_;
}

void SimulatorVar::WriteToSimulator(string name, float valueInput) {
  // Format a message to send to the simulator.
  string message("set " + name + " " + to_string(valueInput) + "\r\n");
  cout << "writing: " + message << endl;
  this->container->sockets.SendToServer(message);
}