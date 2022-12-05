//
// Created by siddr on 12/2/2022.
//

#ifndef MOVIESP5_CLASSIC_H
#define MOVIESP5_CLASSIC_H

#include "Movie.h"

class Classic : public Movie {
private:
  int releaseYear;
  int releaseMonth;
  std::string majorActor;

public:
  friend std::ostream &operator<<(std::ostream &out, const Classic &classic);

  Classic(int stock, const std::string &director, const std::string &title,
          std::string majorActor, int releaseMonth, int releaseYear);

  int getReleaseYear() const;

  int getReleaseMonth() const;

  const std::string &getMajorActor() const;
};

#endif // MOVIESP5_CLASSIC_H
