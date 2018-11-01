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

#include "bicycle.h"
#include "zip_car.h"
#include "scooter.h"

class Rental_Transport_Factory
{
  public:

      Rental_Transport_Factory();

      virtual ~Rental_Transport_Factory();

      virtual Rental_Transport* create() const = 0;

  protected:

      Location* loc;

      int* base_attributes;

      Location* get_location() const;

      int* get_base_attributes() const;


};

class Scooter_Factory : public Rental_Transport_Factory
{
  public:

    Rental_Transport* create() const;
};

class Zip_Car_Factory : public Rental_Transport_Factory
{
  public:

    Rental_Transport* create() const;
};

class Bicycle_Factory : public Rental_Transport_Factory
{
  public:
    
    Rental_Transport* create() const;
};

#endif // RENTAL_FACTORY

