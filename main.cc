#include <iostream>
#include <vector>

#include "model.hh"
#include "unit.hh"

using namespace std;


int main() {

  vector<Model> model_list = {
      {"Champion", "IO760", 32, false},
      {"Switezsj", "IO960T", 256, true},
      {"Adrszpach", "IO270", 64, false}};

  vector<Unit> unit_list = {
    {"KF0", &model_list[0], ORDERED, "2026-05-11 10:32:01"},
    {"0D4", &model_list[1], ORDERED, "2026-04-29 18:59:21"},
    {"Z11", &model_list[2], ORDERED, "2026-05-11 11:32:42"},
    {"000", nullptr, ORDERED, "2026-05-31 23:59:59"},
    {"CRT", &model_list[1], ORDERED, "2026-06-02 22:20:24"},
    {}
  };
  
  for (long unsigned int i = 0; i < unit_list.size(); i++) {
    unit_list[i].statusSwitch(IN_PROGRESS);
    cout << unit_list[i] << endl;
  }
  
  
  return 0;
}
