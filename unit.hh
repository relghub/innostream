#ifndef UNIT_CLASS
#define UNIT_CLASS

#include <string>
#include <chrono>

#include "model.hh"

enum Status { ORDERED, IN_PROGRESS, COMPLETED, CANCELED };

class Unit {
private:
  std::string serviceTag;
  const Model* baseModel;
  Status currentStatus;
  std::chrono::time_point<std::chrono::system_clock> orderTimestamp;

public:
  Unit(std::string service_tag = "000000", const Model* base_model = nullptr, 
       Status status = ORDERED, std::chrono::time_point<std::chrono::system_clock> timestamp = std::chrono::system_clock::now());

  std::string statusConversion(const Status status) const;
  void statusSwitch(Status status);

  long long getAgeInSeconds() const;
  
  friend std::ostream& operator<<(std::ostream& os, const Unit& u);
};

#endif
