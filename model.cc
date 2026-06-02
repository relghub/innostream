#include <iostream>
#include <stdexcept>

#include "model.hh"

using namespace std;

Model::Model(string code_name, string cpu, int ram,
             bool is_workstation) {
  this->codename = code_name;
  this->cpuModel = cpu;
  if (ram >= 0) {
    this->ramQuantity = ram;
  } else {
    throw invalid_argument("Podano ujemna ilosc pamieci operacyjnej w modelu.");
  }
  this->isWorkstation = is_workstation;
}

void Model::printSpec() {
  cout << "Nazwa kodowa: " << codename << ";\n"
       << "Model procesora: " << cpuModel << ";\n"
       << "Ilosc pamieci operacyjnej: " << ramQuantity << " GB;\n"
       << (isWorkstation ? "Stacja robocza" : "Serwer rackowy") << "\n";
}
