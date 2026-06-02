#ifndef MODEL_CLASS
#define MODEL_CLASS

#include <ostream>
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

  friend std::ostream& operator<<(std::ostream& os, const Model& m);
};


#endif
