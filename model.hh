#ifndef MODEL_CLASS
#define MODEL_CLASS

#include <string>

enum Status { ORDERED, IN_PROGRESS, COMPLETED, CANCELED };

class Model {
private:
  std::string serviceTag;
  std::string codename;
  std::string cpuModel;
  Status currentStatus;
  std::string orderTimestamp;
  unsigned int ramQuantity;
  bool isWorkstation;

public:
  Model(std::string service_tag = "000000",
        std::string code_name = "UNDEFINED",
        std::string cpu = "GENUINEANY",
        Status status = ORDERED,
        std::string timestamp = "2000-01-01 00:00:00",
        int ram = 0,
        bool is_workstation = false);
  
  std::string statusConversion(Status status);
  void statusSwitch(Status status);
  
  void printSpec();
};


#endif
