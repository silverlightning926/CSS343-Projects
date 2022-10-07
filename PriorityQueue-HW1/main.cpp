/*
* main.cpp
*
* This is the main driver class for Covid Priority Queue - HW1
*
* It handles reading from a file and parsing the data and creating
    patient objects from that data. It then adds that data to the
    CovidPriorityQueue object. The class then asks the user for how
    many doses are available, and looks at and prints the top of the
    queue and pops the queue accordingly. It will print as many patients
    as the user requested unless the queue becomes empty.
*/

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "covidpriorityqueue.h"
#include "patient.h"

int main() {

  std::ifstream infile("./patients.txt"); // Accessing The File

  std::vector<std::vector<std::string>> data;

  while (infile) { // Reading The File
    std::string s;
    if (!getline(infile, s))
      break;

    std::istringstream ss(s);
    std::vector<std::string> record;

    while (ss) {
      if (!getline(ss, s, ',')) // Parsing The File
        break;
      record.push_back(s);
    }

    data.push_back(record);
  }
  if (!infile.eof()) {
    std::cerr << "Error Finding File!\n"; // If File Not Found
  }

  CovidPriorityQueue covid_pq; // Creating CovidPriorityQueue Object

  for (int i = 1; i < data.size();
       i++) { // Creating Patient Objects From Parsed Data &
              // Adding Them To The Queue
    std::string name;
    int age;
    bool has_precondition;

    for (int j = 0; j < 3; j++) {
      switch (j) {
      case 0:
        name = data[i][j];
        break;
      case 1:
        age = std::stoi(data[i][j]);
        break;
      default:
        has_precondition = data[i][j] == " Yes";
        break;
      }
    }

    covid_pq.push(Patient(name, age, has_precondition));
  }

  int vaccine_doses;

  std::cout << "Enter Available Doses: "; // Querying The User For The Amount Of
                                          // Available Doses

  while (!(std::cin >>
           vaccine_doses)) { // Requery The User If Input Is Not A Number
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again: ";
  }

  std::cout << std::endl;

  for (int i = 0; i < vaccine_doses && !covid_pq.empty();
       ++i) { // Print Out Top Priority Patients
    std::cout << i + 1 << ". " << covid_pq.top() << std::endl;
    covid_pq.pop();
  }

  return 0;
}