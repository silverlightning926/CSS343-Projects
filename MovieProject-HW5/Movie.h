//
// Created by siddr on 11/30/2022.
//

#ifndef MOVIESP5_MOVIE_H
#define MOVIESP5_MOVIE_H
#pragma once
#include <string>
#include <utility>

class Movie {
public:
private:
  std::string title;
  std::string director;

  int stock;

public:
  const std::string &getTitle() const { return title; }

  void setTitle(const std::string &newTitle) { Movie::title = newTitle; }

  const std::string &getDirector() const { return director; }

  void setDirector(const std::string &newDirector) {
    Movie::director = newDirector;
  }

  int getStock() const { return stock; }

  void setStock(int newStock) { Movie::stock = newStock; }
};

#endif // MOVIESP5_MOVIE_H
