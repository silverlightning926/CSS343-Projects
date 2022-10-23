#include "threadedBST.h"
#include <bits/stdc++.h>
#include <vector>

// output overload
std::ostream &operator<<(std::ostream &out, const ThreadedBST &bst) {
  out << "[";

  for (int i : bst.inorderTraversal()) {
    out << i << ", ";
  }

  out << "]" << std::endl;

  return out;
}

// assignment overload for copying
ThreadedBST &ThreadedBST::operator=(const ThreadedBST &bst) {
  if (&bst != this) {
    clear(headPtr);
  }

  totalNodes = bst.totalNodes;
  headPtr = buildSubTree(bst.inorderTraversal(), 0,
                         static_cast<int>(bst.inorderTraversal().size() - 1));
  threadTree(headPtr);
  return *this;
}

// conor
// n equals the total number of nodes in the tree
ThreadedBST::ThreadedBST(int n) : totalNodes{n} {

  // vector for adding inputs
  std::vector<int> nums;
  for (int i = 1; i <= n; i++) {
    nums.push_back(i);
  }
  // assign headptr and start recursive call to build tree, then thread it
  headPtr = buildSubTree(nums, 0, nums.size() - 1);
  threadTree(headPtr);
}

// helper function to thread a tree
void ThreadedBST::threadTree(Node *headPtr) {

  // find left most child of tree
  Node *current_node = headPtr;
  while (current_node->leftPtr != nullptr) {
    current_node = current_node->leftPtr;
  }
  if (current_node->rightPtr != nullptr) {
    current_node = current_node->rightPtr;
  }

  // traverse tree and create threads when necessary
  while (current_node->value < totalNodes) {

    if (current_node->rightPtr == nullptr) { // thread needed
      // create thread and follow it
      current_node->rightPtr = getEntry(current_node->value + 1);
      current_node->isThread = true;
      current_node = current_node->rightPtr;

    } else if (current_node->leftPtr != nullptr) {
      // explore left child/subtree
      current_node = current_node->leftPtr;
    } else {
      // explore right child/subtree
      current_node = current_node->rightPtr;
    }
  }
}

// helper function to build subtrees recursively
// returns a Node* to make recursion possible
Node *ThreadedBST::buildSubTree(const std::vector<int> &nums, int lower,
                                int upper) {

  if (lower > upper)
    return nullptr;

  /* Find index of the maximum element from Binary Tree */
  int i = max(nums, lower, upper);

  /* Pick the maximum value and make it root */
  Node *root = newNode(nums[i]);

  /* If this is the only element in inorder[start..end],
  then return it */
  if (lower == upper)
    return root;

  /* Using index in Inorder traversal, construct left and
  right subtress */
  root->leftPtr = buildSubTree(nums, lower, i - 1);
  root->rightPtr = buildSubTree(nums, i + 1, upper);

  return root;
}

int ThreadedBST::max(std::vector<int> nums, int strt, int end) {
  int i = 0;
  int max = nums[strt];
  int maxind = strt;
  for (i = strt + 1; i <= end; i++) {
    if (nums[i] > max) {
      max = nums[i];
      maxind = i;
    }
  }

  return maxind;
}

Node *ThreadedBST::newNode(int value) {
  Node *new_node = new Node();
  new_node->value = value;
  new_node->isThread = false;
  new_node->leftPtr = nullptr;
  new_node->rightPtr = nullptr;
  return new_node;
}

ThreadedBST::ThreadedBST(const ThreadedBST &tbst)
    : totalNodes{static_cast<int>(tbst.inorderTraversal().size())} {

  headPtr = buildSubTree(tbst.inorderTraversal(), 0,
                         static_cast<int>(tbst.inorderTraversal().size() - 1));
  threadTree(headPtr);
}

// deor
ThreadedBST::~ThreadedBST() { clear(headPtr); }

void ThreadedBST::clear(Node *node) {

  if (node->leftPtr != nullptr) {
    clear(node->leftPtr);
  }

  if (node->rightPtr != nullptr && !node->isThread) {
    clear(node->rightPtr);
  }

  delete node;
}

Node *ThreadedBST::getEntry(int n) const {
  Node *pointer = headPtr;

  while (pointer != nullptr) {
    if (pointer->value == n) {
      return pointer;
    }
    if (n < pointer->value) {
      pointer = pointer->leftPtr;
    } else {
      pointer = pointer->rightPtr;
    }
  }
  return nullptr;
}

// iterator to do inorder traversal of the tree
std::vector<int> ThreadedBST::inorderTraversal() const {
  std::vector<int> inorder_tree;

  Node *pointer = headPtr;

  while (pointer->leftPtr != nullptr)
    pointer = pointer->leftPtr;

  while (pointer != nullptr) {
    inorder_tree.push_back(pointer->value);
    pointer = findInOrderSuccessor(pointer);
  }

  return inorder_tree;
}

// removes a node
Node *ThreadedBST::remove(int value) {
  std::vector<int> inorder_bst = inorderTraversal();
  std::vector<int> new_tree;

  for (int i : inorder_bst) {
    if (i != value) {
      new_tree.push_back(i);
      totalNodes--;
    }
  }

  clear(headPtr);

  headPtr = buildSubTree(new_tree, 0, new_tree.size() - 1);
  threadTree(headPtr);

  return headPtr;
}

Node *ThreadedBST::findInOrderSuccessor(Node *node) const {
  if (node->isThread)
    return node->rightPtr;

  Node *pointer = headPtr;

  if (pointer->rightPtr != nullptr) {
    while (pointer->leftPtr != nullptr)
      pointer = pointer->leftPtr;

    return pointer;
  }

  return nullptr;
}