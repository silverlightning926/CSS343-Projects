/*
 * covidpriorityqueue.h
 *
 * Header File For Covid Priority Queue Class
 */

#ifndef COVIDPRIORITYQUEUE_P1_COVIDPRIORITYQUEUE_H
#define COVIDPRIORITYQUEUE_P1_COVIDPRIORITYQUEUE_H

#include <iostream>
#include <queue>

#include "patient.h"

class CovidPriorityQueue {
private:
  std::priority_queue<Patient> pq; // Internal STL Priority Queue

public:
  CovidPriorityQueue(); // Covid Priority Queue Class Constructor

  bool empty() const; // Function To Check If The Queue Is Empty

  void
  push(const Patient &newEntry); // Function To Push New Items Into The Queue

  void pop(); // Function To Pop The Top Item Of The Queue

  Patient &top(); // Function To Peek At The Top Of The Queue
};

#endif // COVIDPRIORITYQUEUE_P1_COVIDPRIORITYQUEUE_H
