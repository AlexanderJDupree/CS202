/*
File: scooter.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef SCOOTER_H
#define SCOOTER_H

#include "rental_transport.h"

class Scooter : public Rental_Transport
{
  public:

    Scooter(int id = 0, int miles = 0, Location loc = Location(), int charge = 0);

    void display() const; // Override

    int rate() const; // Override

    int battery_level() const;

  protected:

    int battery;

  private:

};

#endif // SCOOTER_H

