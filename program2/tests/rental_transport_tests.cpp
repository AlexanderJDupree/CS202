/*
File: rental_transport_tests.cpp

Description: Unit tests for the rental_transport abstract base class

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include <catch.hpp>
#include "rental_transport.h"

class derived_rental : public Rental_Transport
{
  public:

    void display() const
    {
        std::cout << "\nDerived Rental\n";
        Rental_Transport::display();
        std::cout << std::string(50, '=') << std::endl;;
        return;
    }

    int rate() const
    {
        return 0;
    }

};

TEST_CASE("Constructing rental_transport derived objects", "[constructors], [rental_transport]")
{
    SECTION("Default construction")
    {
        Rental_Transport* test = new derived_rental;

        REQUIRE(test->total_miles() == 0);
        REQUIRE(test->rate() == 0);

        test->display();

        delete test;
    }
}

