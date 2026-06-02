#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <stdexcept>

#include "unit.hh"

using namespace std;

Unit::Unit(string service_tag, const Model *base_model_ptr, Status status,
           chrono::time_point<chrono::system_clock> timestamp)
  : serviceTag(service_tag), baseModel(base_model_ptr), currentStatus(status), orderTimestamp(timestamp) {}

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

long long Unit::getAgeInSeconds() const {
  auto now = chrono::system_clock::now();
  auto duration = now - orderTimestamp;
  return chrono::duration_cast<chrono::seconds>(duration).count();
}

ostream &operator<<(ostream &os, const Unit &u) {
  time_t timestamp = chrono::system_clock::to_time_t(u.orderTimestamp); 
  os << "Service Tag: " << u.serviceTag << ";\n"
     << "Model podstawowy: "
     << (u.baseModel == nullptr ? "BRAK" : u.baseModel->codenameGet()) << ";\n"
     << "Status: " << u.statusConversion(u.currentStatus) << ";\n"
     << "Czas otrzymania zamowienia: " << ctime(&timestamp)
     << "Czas na tasmie: " << u.getAgeInSeconds() << " sekund;\n";
  return os;
}
