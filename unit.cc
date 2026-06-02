#include <iostream>
#include <string>
#include <stdexcept>

#include "unit.hh"

using namespace std;

Unit::Unit(string service_tag, Model base_model, Status status,
           string timestamp) {
  this->serviceTag = service_tag;
  this->baseModel = base_model;
  this->currentStatus = status;
  this->orderTimestamp = timestamp;
}

string Unit::statusConversion(Status status) {
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

void Unit::statusSwitch(Status status) { this->currentStatus = status; }

void Unit::printSpec() {
  cout << "Service Tag: " << serviceTag << ";\n"
     //<< "Model podstawowy: " << baseModel << ";\n"
       << "Status: " << statusConversion(currentStatus) << ";\n"
       << "Czas otrzymania zamowienia: " << orderTimestamp << ";\n"; // do rozbudowania z osobna klasa
}
