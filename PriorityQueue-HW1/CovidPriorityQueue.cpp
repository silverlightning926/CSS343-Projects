#include "CovidPriorityQueue.h"

CovidPriorityQueue::CovidPriorityQueue() = default;

bool CovidPriorityQueue::empty() const { return pq.empty(); }

void CovidPriorityQueue::push(const Patient &newEntry) { pq.push(newEntry); }

void CovidPriorityQueue::pop() { pq.pop(); }

Patient &CovidPriorityQueue::top() { return const_cast<Patient &>(pq.top()); }
