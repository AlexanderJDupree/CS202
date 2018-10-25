/*
File: rental_factory.cpp

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "interface.h"
#include "rental_factory.h"

/****** SCOOTER FACTORY ******/

Rental_Transport* Scooter_Factory::create() const
{
    using namespace Interface;

    char buffer1[100];
    char buffer2[100];

    std::cout << "\nFirst, please enter the location info of the unit";

    get_char_input(buffer1, 100, "\n\tEnter street name: ");
    get_char_input(buffer2, 100, "\tEnter nearest intersecting street: ");

    Location location(buffer1, buffer2);

    std::cout << "\nNow enter vehicle particular information";

    return new Scooter(
            get_input<int>("\nEnter ID number: "),
            get_input<int>("Current mileage: "),
            get_input<int>("Enter current charge level (0 - 100): "),
            location );
}

