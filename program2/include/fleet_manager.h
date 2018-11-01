/*
File: fleet_manager.h

Description:

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

    ~Fleet_Manager();

    void add_vehicle(Rental_Transport_Factory* factory);

    void display_earnings() const;

  protected:

  private:

};

#endif // FLEET_MANAGER_H

