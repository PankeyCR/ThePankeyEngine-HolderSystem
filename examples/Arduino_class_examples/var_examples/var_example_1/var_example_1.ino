
#include "pankey_HolderSystem.hpp"

using namespace pankey::HolderSystem;

void setup() {
  Serial.begin(9600);
  createMemoryManager();
}

void loop() {
  var i = 15;
  Serial.println(i.getValue<int>());
}




//