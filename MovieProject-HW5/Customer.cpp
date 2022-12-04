//
// Created by siddr on 11/23/2022.
//

#include "Customer.h"

#include <bits/stdc++.h>
#include <utility>

Customer::Customer(std::string firstName, std::string lastName,
                   std::string customerID) {
  this->firstName_ = std::move(firstName);
  this->lastName_ = std::move(lastName);
  this->customerID_ = std::move(customerID);
}

void Customer::borrowMovie(const Movie &movie) {
  currentMovies_.push_back(movie);
  customerHistory_.emplace_back(movie, "B");
}

void Customer::returnMovie(const Movie &movie) {
  for (int i = 0; i < currentMovies_.size(); i++) {
    if (currentMovies_[i].getTitle() == movie.getTitle() &&
        currentMovies_[i].getDirector() == movie.getDirector())
      currentMovies_.erase(currentMovies_.begin() + i);
  }

  customerHistory_.emplace_back(movie, "R");
}

void Customer::history() {
  std::cout << "History For Customer " << customerID_ << " - " << firstName_
            << " " << lastName_ << std::endl;
  for (const std::pair<Movie, std::string> &pair : customerHistory_) {
    std::cout << "\t" << pair.second << " | " << pair.first.getTitle() << " by "
              << pair.first.getDirector() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Customer &customer) {
  out << customer.firstName_ << " " << customer.lastName_ << " - "
      << customer.customerID_;
  return out;
}
