//
// Created by siddr on 12/1/2022.
//

#ifndef MOVIESP5_DRAMA_H
#define MOVIESP5_DRAMA_H

#include "Movie.h"
#include <string>

class Drama : public Movie {
private:
  int releaseYear;

public:
  friend std::ostream &operator<<(std::ostream &out, const Drama &drama);

  bool operator<(const Drama &drama) const;

  Drama(int stock, const std::string &director, const std::string &title,
        int releaseYear);

  int getReleaseYear() const;
};

#endif // MOVIESP5_DRAMA_H
