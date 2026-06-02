#ifndef UNIT_CLASS
#define UNIT_CLASS

#include <string>

#include "model.hh"

enum Status { ORDERED, IN_PROGRESS, COMPLETED, CANCELED };

class Unit {
private:
  std::string serviceTag;
  Model baseModel;
  Status currentStatus;
  std::string orderTimestamp;

public:
  Unit(std::string service_tag = "000000", Model base_model = Model(), 
       Status status = ORDERED, std::string timestamp = "2000-01-01 00:00:00");

  std::string statusConversion(const Status status) const;
  void statusSwitch(Status status);

  friend std::ostream& operator<<(std::ostream& os, const Unit& u);
};

#endif
