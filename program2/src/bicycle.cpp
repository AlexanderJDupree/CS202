/*
File: bicycle.cpp

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "bicycle.h"

Bicycle::Bicycle(int id, int miles, Location loc)
    : Rental_Transport(id, miles, loc) {}

void Bicycle::display() const
{
    std::cout << "\nBiketown Bike\n";
    Rental_Transport::display();
    std::cout << std::string(50, '=') << std::endl;
    return;
}

float Bicycle::rate() const
{
    return .75;
}

float Bicycle::earnings() const
{
    return rate() * miles + (2 * (miles % 5));
}

