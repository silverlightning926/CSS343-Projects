//
// Created by siddr on 11/30/2022.
//

#include "Comedy.h"
#include <iostream>

Comedy::Comedy(int stock, const std::string &director, const std::string &title,
               int releaseYear)
    : releaseYear(releaseYear) {
  this->setStock(stock);
  this->setDirector(director);
  this->setTitle(title);
}

int Comedy::getReleaseYear() const { return releaseYear; }

std::ostream &operator<<(std::ostream &out, const Comedy &comedy) {
  out << "COMEDY (F): " << comedy.getTitle() << " by " << comedy.getDirector()
      << " - " << comedy.getReleaseYear() << " [" << comedy.getStock() << "]";
  return out;
}

bool Comedy::operator<(const Comedy &comedy) const {
    if (getTitle() == comedy.getTitle()) {
        return getReleaseYear() < comedy.getReleaseYear();
    }

    return getTitle() < comedy.getTitle();
}
