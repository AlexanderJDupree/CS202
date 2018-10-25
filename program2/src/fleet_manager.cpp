/*
File: fleet_manager.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "fleet_manager.h"

Fleet_Manager::Fleet_Manager() {}

Fleet_Manager::~Fleet_Manager()
{
    for (Fleet::iterator it = fleet.begin(); it != fleet.end(); ++it)
    {
        delete *it;
    }
}

