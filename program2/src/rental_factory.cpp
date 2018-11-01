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

/****** RENTAL_TRANSPORT_FACTORY ******/

Rental_Transport_Factory::Rental_Transport_Factory()
    : loc(get_location()), base_attributes(get_base_attributes()) {}

Rental_Transport_Factory::~Rental_Transport_Factory()
{
    delete loc;

    delete [] base_attributes;
}

Location* Rental_Transport_Factory::get_location() const
{
    using namespace Interface;

    char buffer1[100];
    char buffer2[100];

    std::cout << "\nFirst, please enter the location info of the unit";

    get_char_input(buffer1, 100, "\n\tEnter street name: ");
    get_char_input(buffer2, 100, "\tEnter nearest intersecting street: ");

    return new Location(buffer1, buffer2);
}

int* Rental_Transport_Factory::get_base_attributes() const
{
    using namespace Interface;

    int* attributes = new int[2];

    std::cout << "\nNow enter unit particular information";

    attributes[0] = get_input<int>("\nEnter ID number: ");

    attributes[1] =  get_input<int>("Current mileage: ");

    return attributes;
}

/****** SCOOTER FACTORY ******/

Rental_Transport* Scooter_Factory::create() const
{
    using namespace Interface;

    return new Scooter(base_attributes[0], base_attributes[1],
                       get_input<int>("Enter current charge level (0 - 100): "),
                       *loc );
}

/****** ZIP_CAR_FACTORY ******/

Rental_Transport* Zip_Car_Factory::create() const
{
    using namespace Interface;

    return new Zip_Car(base_attributes[0], base_attributes[1],
                       get_input<int>("Enter current fuel level (gallons): "),
                       *loc );
}

/****** BICYCLE_FACTORY ******/

Rental_Transport* Bicycle_Factory::create() const
{
    using namespace Interface;

    return new Bicycle(base_attributes[0], base_attributes[1], *loc );
}

