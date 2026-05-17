#include <vector>

#include "model.hh"

using namespace std;


int main() {

  // Model model1 = {"KF0", "Champion", "IO760", IN_PROGRESS, "2026-05-11 10:32:01", 32, false};
  // Model model2 = {"0D4", "Switezsj", "IO960T", CANCELED, "2026-04-29 18:59:21",                  256,   true};

  vector<Model> model_list = {
      {"KF0", "Champion", "IO760", ORDERED, "2026-05-11 10:32:01", 32, false},
      {"0D4", "Switezsj", "IO960T", ORDERED, "2026-04-29 18:59:21", 256, true},
      {"Z11", "Adrszpach", "IO270", ORDERED, "2026-05-11 11:32:42", 64, false}};

  for (long unsigned int i = 0; i < model_list.size(); i++) {
    model_list[i].statusSwitch(IN_PROGRESS);
    model_list[i].printSpec();
  }
  
  
  return 0;
}
