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

ostream& operator<<(ostream& os, const Model& m) {
  os << "Nazwa kodowa: " << m.codename << ";\n"
     << "Model procesora: " << m.cpuModel << ";\n"
     << "Ilosc pamieci operacyjnej: " << m.ramQuantity << " GB;\n"
     << (m.isWorkstation ? "Stacja robocza" : "Serwer rackowy") << "\n";
  return os;
}

