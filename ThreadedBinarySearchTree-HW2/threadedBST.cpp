#include "threadedBST.h"
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;

// output overload
ostream &operator<<(ostream &out, const ThreadedBST &bst) {
  out << "[";

  for (int i : bst.inorderTraversal()) {
    out << i << ", ";
  }

  out << "]" << endl;

  return out;
}

// assignment overload for copying
ThreadedBST &ThreadedBST::operator=(const ThreadedBST &bst) {
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
  vector<int> nums;
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
  Node *currentNode = headPtr;
  while (currentNode->leftPtr != nullptr) {
    currentNode = currentNode->leftPtr;
  }
  if (currentNode->rightPtr != nullptr) {
    currentNode = currentNode->rightPtr;
  }

  // traverse tree and create threads when necessary
  while (currentNode->value < totalNodes) {

    if (currentNode->rightPtr == nullptr) { // thread needed
      // create thread and follow it
      currentNode->rightPtr = getEntry(currentNode->value + 1);
      currentNode->isThread = true;
      currentNode = currentNode->rightPtr;

    } else if (currentNode->leftPtr != nullptr) {
      // explore left child/subtree
      currentNode = currentNode->leftPtr;
    } else {
      // explore right child/subtree
      currentNode = currentNode->rightPtr;
    }
  }
}

// helper function to build subtrees recursively
// returns a Node* to make recursion possible
Node *ThreadedBST::buildSubTree(const vector<int> &nums, int lower, int upper) {

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

int ThreadedBST::max(vector<int> nums, int strt, int end) {
  int i, max = nums[strt], maxind = strt;
  for (i = strt + 1; i <= end; i++) {
    if (nums[i] > max) {
      max = nums[i];
      maxind = i;
    }
  }

  return maxind;
}

Node *ThreadedBST::newNode(int value) {
  Node *newNode = new Node();
  newNode->value = value;
  newNode->isThread = false;
  newNode->leftPtr = nullptr;
  newNode->rightPtr = nullptr;
  return newNode;
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

// returns true if empty, false if not
bool ThreadedBST::isEmpty() const { return (headPtr == nullptr); }

Node *ThreadedBST::leftMost(Node *n) const {
  if (n == nullptr)
    return nullptr;

  while (n->leftPtr != nullptr)
    n = n->leftPtr;

  return n;
}

// iterator to do inorder traversal of the tree
vector<int> ThreadedBST::inorderTraversal() const {
  vector<int> inorderTree;

  Node *pointer = leftMost(headPtr);

  while (pointer != nullptr) {
    inorderTree.push_back(pointer->value);

    if (pointer->isThread)
      pointer = pointer->rightPtr;
    else
      pointer = leftMost(pointer->rightPtr);
  }

  return inorderTree;
}

// removes a node
Node *ThreadedBST::remove(int value) {
  vector<int> inorderBST = inorderTraversal();
  vector<int> newTree;

  for (int i : inorderBST) {
    if (i != value) {
      newTree.push_back(i);
      totalNodes--;
    }
  }

  clear(headPtr);

  headPtr = buildSubTree(newTree, 0, newTree.size() - 1);
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

Node *ThreadedBST::findInorderPredecessor(Node *node) {
  Node *pointer = node;

  pointer = pointer->leftPtr;
  while (!pointer->isThread)
    pointer = pointer->rightPtr;
  return node;
}