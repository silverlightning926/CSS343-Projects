//
// Created by siddr on 10/5/2022.
//

#include "Patient.h"
#include <iostream>

Patient::Patient(std::string name, int age, bool hasPrecondition) {
  this->name = std::move(name);
  this->age = age;
  this->hasPrecondition = hasPrecondition;
}

std::string Patient::getName() const { return name; }

void Patient::setName(std::string newValue) { name = std::move(newValue); }

int Patient::getAge() const { return age; }

void Patient::setAge(int newValue) { age = std::move(newValue); }

bool Patient::getHasPrecondition() const { return hasPrecondition; }

void Patient::setHasPrecondition(bool newValue) { hasPrecondition = newValue; }

int Patient::getPriorityValue() const {
  return getAge() * (getHasPrecondition() ? 4 : 1);
}

bool Patient::operator<(const Patient &patient) const {
  return getPriorityValue() < patient.getPriorityValue();
}

bool Patient::operator<=(const Patient &patient) const {
  return getPriorityValue() <= patient.getPriorityValue();
}

bool Patient::operator>(const Patient &patient) const {
  return getPriorityValue() > patient.getPriorityValue();
}

bool Patient::operator>=(const Patient &patient) const {
  return getPriorityValue() >= patient.getPriorityValue();
}

std::ostream &operator<<(std::ostream &out, const Patient &patient) {
  out << "[ Name: ";
  out << patient.getName();
  out << ", Age: ", out << patient.getAge();
  out << ", Has Precondition: ",
      out << std::boolalpha << patient.getHasPrecondition();
  out << " ]";
  return out;
}
