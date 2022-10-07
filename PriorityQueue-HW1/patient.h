/*
 * patient.h
 *
 * Header File For Patient Class
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
  Patient(std::string name, int age,
          bool hasPrecondition); // Constructor For Parent Object
  Patient() = delete;            // Delete Basic Constructor

  friend std::ostream &
  operator<<(std::ostream &out,
             const Patient &patient); // Overloading Print Operator

  std::string getName() const;        // Getter Function dor name Field
  void setName(std::string newValue); // Setter Function For name Field

  int getAge() const;        // Getter Function For age Field
  void setAge(int newValue); // Setter Function For age Field

  bool getHasPrecondition() const; // Getter Function For hasPrecondition Field
  void
  setHasPrecondition(bool newValue); // Setter Function For hasPreconditionField

  int getPriorityValue()
      const; // Function To Get Priority Value of the Patient Object

  bool operator<(const Patient &patient) const;  // Overloading < Operator
  bool operator<=(const Patient &patient) const; // Overloading <= Operator

  bool operator>(const Patient &patient) const;  // Overloading > Operator
  bool operator>=(const Patient &patient) const; // Overloading >= Operator
};

#endif // COVIDPRIORITYQUEUE_P1_PATIENT_H
