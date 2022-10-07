/*
* patient.h
*/

#ifndef COVIDPRIORITYQUEUE_P1_PATIENT_H
#define COVIDPRIORITYQUEUE_P1_PATIENT_H

#include <string>

class Patient {
private:
  std::string name;
  int age;
  bool hasPrecondition;

public:
  Patient(std::string name, int age, bool hasPrecondition);
  Patient() = delete;

  friend std::ostream &operator<<(std::ostream &out, const Patient &patient);

  std::string getName() const;
  void setName(std::string newValue);

  int getAge() const;
  void setAge(int newValue);

  bool getHasPrecondition() const;
  void setHasPrecondition(bool newValue);

  int getPriorityValue() const;

  bool operator<(const Patient &patient) const;
  bool operator<=(const Patient &patient) const;

  bool operator>(const Patient &patient) const;
  bool operator>=(const Patient &patient) const;
};

#endif // COVIDPRIORITYQUEUE_P1_PATIENT_H
