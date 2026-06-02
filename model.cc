#include <iostream>
#include <stdexcept>

#include "model.hh"

using namespace std;

Model::Model(string code_name, string cpu, int ram,
             bool is_workstation): codename(code_name), cpuModel(cpu), isWorkstation(is_workstation) {
  if (ram >= 0) {
    this->ramQuantity = ram;
  } else {
    throw invalid_argument("Podano ujemna ilosc pamieci operacyjnej w modelu.");
  }
}

string Model::codenameGet() const {return this->codename;}

ostream& operator<<(ostream& os, const Model& m) {
  os << "Nazwa kodowa: " << m.codename << ";\n"
     << "Model procesora: " << m.cpuModel << ";\n"
     << "Ilosc pamieci operacyjnej: " << m.ramQuantity << " GB;\n"
     << (m.isWorkstation ? "Stacja robocza" : "Serwer rackowy") << "\n";
  return os;
}

