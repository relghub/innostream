#include <iostream>
#include <stdexcept>

#include "model.hh"

using namespace std;

Model::Model(string service_tag, string code_name, string cpu, Status status,
             string timestamp, int ram,
             bool is_workstation) {
  this->serviceTag = service_tag;
  this->codename = code_name;
  this->cpuModel = cpu;
  this->currentStatus = status;
  this->orderTimestamp = timestamp;
  if (ram >= 0) {
    this->ramQuantity = ram;
  } else {
    throw invalid_argument("Podano ujemna ilosc pamieci operacyjnej w modelu.");
  }
  this->isWorkstation = is_workstation;
}

string Model::statusConversion(Status status) {
  switch (status) {
  case ORDERED:
    return "Zamowiono";
  case IN_PROGRESS:
    return "W toku";
  case COMPLETED:
    return "Zakonczony";
  case CANCELED:
    return "Skasowany";
  default:
    throw invalid_argument("Podano nieistniejacy status zamowienia.");
  }
}

void Model::statusSwitch(Status status) {
  this->currentStatus = status;
}

void Model::printSpec() {
  cout << "Service Tag: " << serviceTag << ";\n"
       << "Nazwa kodowa: " << codename << ";\n"
       << "Model procesora: " << cpuModel << ";\n"
       << "Status: " << statusConversion(currentStatus) << ";\n"
       << "Czas otrzymania zamowienia: " << orderTimestamp << ";\n" // do rozbudowania z osobna klasa
       << "Ilosc pamieci operacyjnej: " << ramQuantity << " GB;\n"
       << (isWorkstation ? "Stacja robocza" : "Serwer rackowy") << "\n";
}
