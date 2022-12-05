//
// Created by siddr on 12/2/2022.
//

#include "Classic.h"
#include <iostream>
#include <utility>

int Classic::getReleaseYear() const { return releaseYear; }

int Classic::getReleaseMonth() const { return releaseMonth; }

const std::string &Classic::getMajorActor() const { return majorActor; }

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