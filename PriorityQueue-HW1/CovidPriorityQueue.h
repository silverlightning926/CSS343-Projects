//
// Created by siddr on 10/5/2022.
//

#ifndef COVIDPRIORITYQUEUE_P1_COVIDPRIORITYQUEUE_H
#define COVIDPRIORITYQUEUE_P1_COVIDPRIORITYQUEUE_H

#include <iostream>
#include <queue>

#include "Patient.h"

class CovidPriorityQueue {
private:
  std::priority_queue<Patient> pq;

public:
  CovidPriorityQueue();

  bool empty() const;

  void push(const Patient &newEntry);

  void pop();

  Patient &top();
};

#endif // COVIDPRIORITYQUEUE_P1_COVIDPRIORITYQUEUE_H
