#include "covidpriorityqueue.h"

CovidPriorityQueue::CovidPriorityQueue() =
    default; // Implementation Of The Constructor

bool CovidPriorityQueue::empty() const {
  return pq.empty();
} // Implementation Of Empty Function

void CovidPriorityQueue::push(const Patient &newEntry) {
  pq.push(newEntry);
} // Implementation Of Push Function

void CovidPriorityQueue::pop() { pq.pop(); } // Implementation Of Pop Function

Patient &CovidPriorityQueue::top() {
  return const_cast<Patient &>(pq.top());
} // Implementation Of Top Function
