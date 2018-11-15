/*
File: rental_transport.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef RENTAL_TRANSPORT_H
#define RENTAL_TRANSPORT_H

#include "location.h"

// service status struct acts as a basic abstract data type for packaging an
// rental transport's repair status and a boolean flag together
struct service_status
{
    service_status(const char* status, bool in_service)
        : status(status), in_service(in_service) {}

    const char* status;
    bool in_service;
};

class Rental_Transport
{
  public:
    
    // Default constructor assigned zero-equivalent values
    Rental_Transport(int id = 0, int miles = 0, Location loc = Location());

    virtual ~Rental_Transport() {};

    // Returns the current mileage of the transport
    virtual const int& total_miles() const;

    // Displays the status of the vehicle
    virtual void display() const;
    
    // Returns true if the unit is in service
    virtual service_status status() const;

    // Returns the hourly (or per mile) rate for the transport
    virtual float rate() const = 0;

    // Returns the total earnings of the transport
    virtual float earnings() const = 0;

  protected:

    int id_number; // ID number is assigned by the client

    int miles; // The current mileage of the transport

    Location location; // Current intersection where transport is located

  private:

};

#endif // RENTAL_TRANSPORT_H

