/*
File: location.cpp

Description: Implementation file for the Location class. Defines methods for 
             construction, destruction, and operator overloads. 

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "location.h"

Location::Location(const char* street_one, const char* street_two)
    : street_one(new char[std::strlen(street_one) + 1]),
      street_two(new char[std::strlen(street_two) + 1])
{
    std::strcpy(this->street_one, street_one);
    std::strcpy(this->street_two, street_two);
}

Location::Location(const self_type& origin)
    : street_one(new char[std::strlen(origin.street_one) + 1]),
      street_two(new char[std::strlen(origin.street_two) + 1])
{
    std::strcpy(street_one, origin.street_one);
    std::strcpy(street_two, origin.street_two);
}

Location::~Location()
{
    delete [] street_one;
    street_one = NULL;

    delete [] street_two;
    street_two = NULL;
}

bool Location::operator==(const self_type& rhs)
{
    return (std::strcmp(street_one, rhs.street_one) == 0) && 
           (std::strcmp(street_two, rhs.street_two) == 0);
}

std::ostream& operator << (std::ostream& os, const Location& location)
{
    os << location.street_one << " and " << location.street_two;
    return os;
}

// copy is passed by VALUE because we want to invoke the copy constructor to do
// the work for us. We just swap resources with the r-value copy
Location& Location::operator=(self_type copy)
{
    // Swap ownership of resources with the copy
    swap(*this, copy);

    // As the copy goes out of scope it destructs with the old data
    return *this;
}

void Location::swap(self_type& new_location, self_type& old_location)
{
    using std::swap;

    // Swaps pointers, reassigns ownership
    swap(new_location.street_one, old_location.street_one);
    swap(new_location.street_two, old_location.street_two);
    return;
}

