//
// Created by siddr on 11/30/2022.
//

#ifndef MOVIESP5_COMEDY_H
#define MOVIESP5_COMEDY_H

#include "Movie.h"
#include <string>

class Comedy : public Movie {
private:
  int releaseYear;

public:
  friend std::ostream &operator<<(std::ostream &out, const Comedy &comedy);

  bool operator<(const Comedy &comedy) const;

  Comedy(int stock, const std::string &director, const std::string &title,
         int releaseYear);

  int getReleaseYear() const;
};

#endif // MOVIESP5_COMEDY_H
