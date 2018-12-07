/*
File: scooter.h

Description: Scooter is derived from the Rental_Transport abstract base class 
             and defines the virtual methods outlined in the interface.

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

    Scooter(int id = 0, int miles = 0, int charge = 0, Location loc = Location());

    // Display Rental_Transport + Scooter information
    void display() const;

    // Returns a service_status object reflecting the battery charge level
    service_status status() const;

    // Returns the per mile rate of the scooter
    float rate() const;

    // Returns the total earnings of the scooter unit
    float earnings() const;

    // Returns the currnet battery charge level
    int battery_level() const;

  protected:

    int battery; // Represents the battery level of the unit

};

#endif // SCOOTER_H

