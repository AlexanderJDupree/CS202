/*
File: zip_car.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef ZIP_CAR_H
#define ZIP_CAR_H

#include "rental_transport.h"

class Zip_Car : public Rental_Transport
{
  public:

    Zip_Car(int id = 0, int miles = 0, int fuel = 0, Location loc = Location());

    void display() const;

    service_status status() const;

    float rate() const;

    float earnings () const;

    int fuel_status() const;

  protected:

    unsigned fuel;
};

#endif // ZIP_CAR_H


