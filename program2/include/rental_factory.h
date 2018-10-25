/*
File: rental_factory.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef RENTAL_FACTORY
#define RENTAL_FACTORY

#include "scooter.h"

class Rental_Transport_Factory
{
  public:

      virtual Rental_Transport* create() const = 0;

      virtual ~Rental_Transport_Factory() {}

  protected:

  private:

};

class Scooter_Factory : public Rental_Transport_Factory
{
  public:

    Rental_Transport* create() const;

  protected:

  private:
};

#endif // RENTAL_FACTORY

