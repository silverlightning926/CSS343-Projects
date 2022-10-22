/*
  File name: threadedBST.h
  Name: Mikhail Ermolenko, Mike Jansen, Tyler Tran
  Date: December, 11, 2021
  This header file contains signatures for all functions and variables.
*/

#pragma once
#ifndef THREADEDBST_H
#define THREADEDBST_H

#include <iostream>
#include <vector>

using namespace std;

class Node {
  friend class ThreadedBST;

private:
  int value;
  Node *leftPtr = nullptr;
  Node *rightPtr = nullptr;
  bool isThread = false; // points at thread or child
};

class ThreadedBST {

  // output overload
  friend ostream &operator<<(ostream &out, const ThreadedBST &bst);

public:
  // assignment overload for copying
  ThreadedBST &operator=(const ThreadedBST &bst);

  // constructor
  // n equals the total number of nodes in the tree
  explicit ThreadedBST(int n);

  // copy constructor
  ThreadedBST(const ThreadedBST &tbst);

  // destructor
  ~ThreadedBST();

  // removes specific element
  // returns true if successful, false if not
  Node *remove(int value);

  // iterator to do inorder traversal of the tree
  vector<int> inorderTraversal() const;

private:
  Node *leftMost(Node *n) const;

  // helper function to thread a tree
  void threadTree(Node *headPtr);

  // clear helper function to recursively delete TBST
  void clear(Node *node);

  // returns true if empty, false if not
  bool isEmpty() const;

  // searchs Tree for a node with specified value
  // returns Node if found, nullptr if not found
  Node *getEntry(int n) const;

  // helper function to build subtrees recursively
  // returns a Node* to make recursion possible
  Node *buildSubTree(const vector<int> &nums, int lower, int upper);

  int max(const vector<int> nums, int strt, int end);

  Node *newNode(int value);

  Node *findInOrderSuccessor(Node *node) const;

  // root pointer (top of tree)
  Node *headPtr = nullptr;

  // total number of nodes in the tree
  int totalNodes;

  Node *findInorderPredecessor(Node *node);
};

#endif