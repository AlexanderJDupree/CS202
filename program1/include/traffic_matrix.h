/*
File: traffic_matrix.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef TRAFFIC_MATRIX_H
#define TRAFFIC_MATRIX_H

#include <iostream>
#include <cstddef> // NULL
#include "vehicle.h" // TODO review

class Traffic_Matrix
{
  public:

    Traffic_Matrix(unsigned lanes=1, unsigned length=100);

    bool insert(Position* obj);

    bool update(Position* obj, const Position* obstacle);

    void display() const;

  protected:

  private:

    const unsigned MAX_LANES;
    const unsigned MAX_LENGTH;

    Position*** _matrix;

    void print_lane(const int& lane) const;
    void print_border() const;
};

#endif //  TRAFFIC_MATRIX_H
