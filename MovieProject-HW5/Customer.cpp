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
  bool found = false;

  for (int i = 0; i < currentMovies_.size(); i++) {
    if (currentMovies_[i].getTitle() == movie.getTitle() &&
        currentMovies_[i].getDirector() == movie.getDirector())
      {
        currentMovies_.erase(currentMovies_.begin() + i);
        found = true;
      }
  }

  if(found)
  {
    customerHistory_.emplace_back(movie, "R");
  }

  else {
    std::cout << "Cannot Return Movie: " << movie.getTitle() << " for Customer: " << customerID_ << std::endl;
  }
}

void Customer::history() {
  std::cout << "History For Customer " << customerID_ << " - " << firstName_
            << " " << lastName_ << std::endl;
  for (const std::pair<Movie, std::string> &pair : customerHistory_) {
    std::cout << "\t" << pair.second << " | " << pair.first.getTitle() << " by "
              << pair.first.getDirector() << std::endl;
  }
}
