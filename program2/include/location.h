/*
File: location.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <cstring>
#include <iostream>

class Location
{
  public:

    typedef Location self_type;

    Location(const char* street_one = "N/A", const char* street_two = "N/A");

    Location(const self_type& origin);
    
    ~Location();

    /****** OPERATORS ******/

    bool operator == (const self_type& rhs);

    friend std::ostream& operator << (std::ostream& os, const self_type& location);

    /****** COPY-ASSIGNMENT AND SWAP ******/

    // creates a copy of the origin, then swaps ownership with the copy
    self_type& operator=(self_type copy);

    // Swaps pointers to each other's resources. effectively reassigning 
    // ownership.
    static void swap(self_type& new_list, self_type& old_list);

  protected:

  private:

    char * street_one;
    char * street_two;
};

#endif // LOCATION_H

