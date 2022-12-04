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
    friend std::ostream &operator<<(std::ostream &out, const Classic &drama);

    Classic(int stock, const std::string& director, const std::string& title, std::string  majorActor, int releaseMonth, int releaseYear);

    int getReleaseYear() const;

    void setReleaseYear(int newReleaseYear);

    int getReleaseMonth() const;

    void setReleaseMonth(int newReleaseMonth);

    const std::string &getMajorActor() const;

    void setMajorActor(const std::string &newMajorActor);
};


#endif //MOVIESP5_CLASSIC_H
