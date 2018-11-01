/*
File: zip_car.cpp

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "zip_car.h"

Zip_Car::Zip_Car(int id, int miles, int fuel, Location loc)
    : Rental_Transport(id, miles, loc), fuel(fuel) {}

void Zip_Car::display() const
{
    std::cout << "\nZip Car\n";
    Rental_Transport::display();
    std::cout << "Fuel: " << fuel << " gal\n" << std::string(50, '=') 
              << std::endl;
    return;
}

service_status Zip_Car::status() const
{
    if (fuel < 5)
    {
        return service_status("Fuel under 5 gal, refuel now", false);
    }

    return service_status("In Service", true);
}

float Zip_Car::rate() const
{
    return 1.5;
}

float Zip_Car::earnings() const
{
    return rate() * miles;
}

int Zip_Car::fuel_status() const
{
    return fuel;
}

