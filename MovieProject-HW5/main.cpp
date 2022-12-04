#include <iostream>
#include "InventoryManager.h"

int main() {
    InventoryManager im;
    im.readFile("./data4movies.txt");
    im.readFile("./data4customers.txt");
    im.readFile("./data4commands.txt");

    return 0;
}
