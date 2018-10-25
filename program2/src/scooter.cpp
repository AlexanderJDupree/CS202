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
              << std::endl;;
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

