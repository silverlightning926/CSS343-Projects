#include "threadedBST.h"
#include <iostream>

void Test1() { // size 1
  int n = 1;
  ThreadedBST orig_tree(n);         // creating a tree
  ThreadedBST new_tree = orig_tree; // copying original tree
  // remove all evens from new_tree
  for (int i = 2; i < n + 1; i += 2) {
    new_tree.remove(i);
  }
  // output
  std::cout << "Original Tree: " << orig_tree << std::endl;
  std::cout << "New Tree: " << new_tree << std::endl << std::endl;
}

void Test2() { // size 4
  int n = 4;
  ThreadedBST orig_tree(n);         // creating a tree
  ThreadedBST new_tree = orig_tree; // copying original tree
  // remove all evens from new_tree
  for (int i = 2; i < n + 1; i += 2) {
    new_tree.remove(i);
  }
  // output
  std::cout << "Original Tree: " << orig_tree << std::endl;
  std::cout << "New Tree: " << new_tree << std::endl << std::endl;
}

int main() {

  Test1();
  Test2();

  return 0;
}
