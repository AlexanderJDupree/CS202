/*
File: bicycle.h

Description: Bicycle is derived from the Rental Transport abstract base class 
             and defines the virtual methods outlined in the interface.

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

    // Displays Rental_Transport + Bicycle specific information 
    void display() const;

    // Returns the per mile rate of the Bicycle.
    float rate() const;

    // Returns the total earnings of the Bicycle
    float earnings () const;
};

#endif  // BICYCLE_H

