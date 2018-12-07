/*
File: traffic_matrix.h

Description: Traffic Matrix utilizes a dynamic 2d array to represent each 
             position available on a one way street. Each index in the array
             is either null or points to a position pointer which is located 
             in the Traffic Manager class. 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef TRAFFIC_MATRIX_H
#define TRAFFIC_MATRIX_H

#include <iostream> // std::cout 
#include <cstddef> // NULL
#include "position.h"

class Traffic_Matrix
{
  public:

    Traffic_Matrix(unsigned lanes=1, unsigned length=100);

    ~Traffic_Matrix();

    // Returns true if the Position was successfully added to the matrix
    bool insert(Position* obj);

    // Tells the object to update it's position and then insert's it into the 
    // matrix
    void update(Position* obj, const Position* obstacle);

    // Loops through the array displaying the state of the matrix
    void display() const;

  protected:

  private:

    const unsigned MAX_LANES;
    const unsigned MAX_LENGTH;

    // 2D Position* array represents available positions along a street
    Position*** _matrix;

    void print_lane(const int& lane) const;
    void print_border() const;
};

#endif //  TRAFFIC_MATRIX_H
