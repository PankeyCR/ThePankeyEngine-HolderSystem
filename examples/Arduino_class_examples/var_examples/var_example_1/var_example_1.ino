
#include "pankey_Memory_Manager_config.hpp"

using namespace pankey;

void setup() {
  Serial.begin(9600);
  createMemoryManager();
}

void loop() {
  var i = 15;
  Serial.println(i.getValue<int>());
}




//