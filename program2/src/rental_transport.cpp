/*
File: rental_transport.cpp

Description: Implementation file for the non pure virtual methods outlined by 
             the Rental_Transport  abstract base class. 

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
              << "\nMileage: " << miles << "\nEarnings: $" << earnings()
              << "\nLocation: " << location << "\nService Status: " 
              << "\n\t" << status().status << '\n';
    return;
}

service_status Rental_Transport::status() const
{
    if (miles > 10000)
    {
        return service_status("In need of 10k Mile Service", false);
    }
    
    return service_status("In Service", true);
}

