//
// Created by siddr on 11/30/2022.
//

#ifndef MOVIESP5_COMEDY_H
#define MOVIESP5_COMEDY_H


#include <string>
#include "Movie.h"

class Comedy : public Movie {
private:
    int releaseYear;

public:
    friend std::ostream &operator<<(std::ostream &out, const Comedy &comedy);

    Comedy(int stock, const std::string& director, const std::string& title, int releaseYear);

    int getReleaseYear() const;

    void setReleaseYear(int newReleaseYear);
};


#endif //MOVIESP5_COMEDY_H
