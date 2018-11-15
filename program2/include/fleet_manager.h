/*
File: fleet_manager.h

Description: Fleet manager is derived from the double linked list class. The
             fleet manager acts as a basic container for rental transport objects
             but specializes methods to add vehicles and display earnings for
             the fleet.

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef FLEET_MANAGER_H
#define FLEET_MANAGER_H

#include "double_list.h"
#include "rental_factory.h"

class Fleet_Manager : public double_linked_list<Rental_Transport*>
{
  public:

    Fleet_Manager();

    // Deallocates each Rental_Transport object before each node is destroyed
    ~Fleet_Manager();

    // Utilizes the factory to instantiate the correct Rental_Transport object
    void add_vehicle(Rental_Transport_Factory* factory);

    // Displays total earnings of the fleet.
    void display_earnings() const;
};

#endif // FLEET_MANAGER_H

