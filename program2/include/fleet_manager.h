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
#include "rental_transport.h"

class Fleet_Manager
{
  public:

    typedef double_linked_list<Rental_Transport*> Fleet;

    Fleet_Manager();

    ~Fleet_Manager();

  protected:

  private:

    Fleet fleet;
};

#endif // FLEET_MANAGER_H

