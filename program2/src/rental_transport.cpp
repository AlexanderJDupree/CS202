/*
File: rental_transport.cpp

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "rental_transport.h"

Rental_Transport::Rental_Transport(int id, int miles, Location loc)
    : id_number(id), miles(miles), location(loc) {}

const int& Rental_Transport::total_miles() const
{
    return miles;
}

void Rental_Transport::display() const
{
    std::cout << std::string(50, '=') << "\nID Number: " << id_number 
              << "\nMileage: " << miles << "\nLocation: " << location << '\n';
              
}

