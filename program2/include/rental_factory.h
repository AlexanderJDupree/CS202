/*
File: rental_factory.h

Description: rental_factory.h contains the declarations of all abstract factory
             classes used in our system. The Rental_Transport_Factory acts as
             the abstract base class for other factory objects and defines 
             methods for creation.

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

      // Returns a new Rental_Transport object
      virtual Rental_Transport* create() const = 0;

  protected:

      Location* loc; // Location of the rental transport

      int* base_attributes; // Contains the ID and Miles base attributes

      // Polls user for location info
      Location* get_location() const;

      // Polls user for base attribute info
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

