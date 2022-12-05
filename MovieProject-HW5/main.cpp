#include "InventoryManager.h"
#include <iostream>

int main() {
  InventoryManager im;
  im.readFile("./data4movies.txt");
  im.readFile("./data4customers.txt");
  im.readFile("./data4commands.txt");
  im.readFile("./invalid.txt");

  return 0;
}
