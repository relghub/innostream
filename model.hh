#ifndef MODEL_CLASS
#define MODEL_CLASS

#include <string>

class Model {
private:
  std::string codename;
  std::string cpuModel;
  unsigned int ramQuantity;
  bool isWorkstation;

public:
  Model(
        std::string code_name = "UNDEFINED",
        std::string cpu = "GENUINEANY",
        int ram = 0,
        bool is_workstation = false);
  
  void printSpec();
};


#endif
