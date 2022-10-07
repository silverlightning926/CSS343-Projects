#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "CovidPriorityQueue.h"
#include "Patient.h"

int main() {
  std::vector<std::vector<std::string>> data;
  std::ifstream infile("./patients.txt");

  while (infile) {
    std::string s;
    if (!getline(infile, s))
      break;

    std::istringstream ss(s);
    std::vector<std::string> record;

    while (ss) {
      if (!getline(ss, s, ','))
        break;
      record.push_back(s);
    }

    data.push_back(record);
  }
  if (!infile.eof()) {
    std::cerr << "Error Finding File!\n";
  }

  CovidPriorityQueue covid_pq;

  for (int i = 1; i < 5; ++i) {
    std::string name;
    int age;
    bool has_precondition;

    for (int j = 0; j < 3; ++j) {
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

  std::cout << "Enter Available Doses: ";

  while (!(std::cin >> vaccine_doses)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again: ";
  }

  std::cout << std::endl;

  for (int i = 0; i < vaccine_doses && !covid_pq.empty(); ++i) {
    std::cout << i + 1 << ". " << covid_pq.top() << std::endl;
    covid_pq.pop();
  }

  return 0;
}