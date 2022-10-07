/*
 * patient.cpp
 *
 *  Cpp File For Patient Class
 */

#include "patient.h"
#include <iostream>

// Implementation Of Patient Class Header
Patient::Patient(std::string name, int age, bool hasPrecondition) {
  this->name = std::move(name);
  this->age = age;
  this->hasPrecondition = hasPrecondition;
}

std::string Patient::getName() const {
  return name;
} // Implementation Of name Field Getter

void Patient::setName(std::string newValue) {
  name = std::move(newValue);
} // Implementation Of name Field Setter

int Patient::getAge() const {
  return age;
} // Implementation Of age Field Getter

void Patient::setAge(int newValue) {
  age = std::move(newValue);
} // Implementation of age Field Setter

bool Patient::getHasPrecondition() const {
  return hasPrecondition;
} // Implementation of hasPrecondition Getter

void Patient::setHasPrecondition(bool newValue) {
  hasPrecondition = newValue;
} // Implementation of hasPrecondition Setter

// Implementation Of getPriority Function
int Patient::getPriorityValue() const {
  return getAge() * (getHasPrecondition() ? 4 : 1);
}

// Implementation of Operator < Overload
bool Patient::operator<(const Patient &patient) const {
  return getPriorityValue() < patient.getPriorityValue();
}

// Implementation of Operator <= Overload
bool Patient::operator<=(const Patient &patient) const {
  return getPriorityValue() <= patient.getPriorityValue();
}

// Implementation of Operator > Overload
bool Patient::operator>(const Patient &patient) const {
  return getPriorityValue() > patient.getPriorityValue();
}

// Implementation of Operator >= Overload
bool Patient::operator>=(const Patient &patient) const {
  return getPriorityValue() >= patient.getPriorityValue();
}

// Implementation of Operator << Overload
std::ostream &operator<<(std::ostream &out, const Patient &patient) {
  out << "[ Name: ";
  out << patient.getName();
  out << ", Age: ", out << patient.getAge();
  out << ", Has Precondition: ",
      out << std::boolalpha << patient.getHasPrecondition();
  out << " ]";
  return out;
}
