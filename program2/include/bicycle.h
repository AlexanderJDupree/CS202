/*
File: bicycle.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef BICYCLE_H
#define BICYCLE_H

#include "rental_transport.h"

class Bicycle : public Rental_Transport
{
  public:

    Bicycle(int id = 0, int miles = 0, Location loc = Location());

    void display() const;

    float rate() const;

    float earnings () const;
};

#endif  // BICYCLE_H

