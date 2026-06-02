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

string Unit::statusConversion(const Status status) const {
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

ostream &operator<<(ostream &os, const Unit &u) {
  os << "Service Tag: " << u.serviceTag << ";\n"
       //<< "Model podstawowy: " << baseModel << ";\n"
       << "Status: " << u.statusConversion(u.currentStatus) << ";\n"
       << "Czas otrzymania zamowienia: " << u.orderTimestamp
       << ";\n"; // do rozbudowania z osobna klasa
  return os;
}
