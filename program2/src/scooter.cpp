/*
File: scooter.cpp

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "scooter.h"

Scooter::Scooter(int id, int miles, int charge, Location loc)
    : Rental_Transport(id, miles, loc), battery(charge) {}

void Scooter::display() const
{
    std::cout << "\nElectric Scooter\n";
    Rental_Transport::display();
    std::cout << "Battery Level: " << battery << "%\n" << std::string(50, '=') 
              << std::endl;
    return;
}

service_status Scooter::status() const
{
    if (battery <= 25)
    {
        return service_status("Battery less than 25%, charge now", false);
    }

    return service_status("In Service", true);
}

float Scooter::rate() const
{
    return .80;
}

float Scooter::earnings() const
{
    return rate() * miles;
}

int Scooter::battery_level() const
{
    return battery;
}

