//
// Created by siddr on 12/2/2022.
//

#include "Classic.h"
#include <iostream>
#include <utility>

int Classic::getReleaseYear() const { return releaseYear; }

void Classic::setReleaseYear(int newReleaseYear) {
  Classic::releaseYear = newReleaseYear;
}

int Classic::getReleaseMonth() const { return releaseMonth; }

void Classic::setReleaseMonth(int newReleaseMonth) {
  Classic::releaseMonth = newReleaseMonth;
}

const std::string &Classic::getMajorActor() const { return majorActor; }

void Classic::setMajorActor(const std::string &newMajorActor) {
  Classic::majorActor = newMajorActor;
}

Classic::Classic(int stock, const std::string &director,
                 const std::string &title, std::string majorActor,
                 int releaseMonth, int releaseYear)
    : releaseYear(releaseYear), releaseMonth(releaseMonth),
      majorActor(std::move(majorActor)) {
  setStock(stock);
  setDirector(director);
  setTitle(title);
}

std::ostream &operator<<(std::ostream &out, const Classic &classic) {
  out << "Classic (C): " << classic.getTitle() << " by "
      << classic.getDirector() << " - " << classic.getReleaseMonth() << " / "
      << classic.getReleaseYear() << " [" << classic.getStock() << "]";
  return out;
}
