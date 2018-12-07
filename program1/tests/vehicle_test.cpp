/*
File: vehicle_test.h

Description: Unit tests for vehicle derived class

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include <catch.hpp>
#include "vehicle.h"

TEST_CASE("Constructing Vehicle Objects", "[vehicle], [constructors]")
{
    SECTION("Default Construction")
    {
        Vehicle obj;

        REQUIRE(obj.lane() == 0);
        REQUIRE(obj.distance() == 0);
    }
}

TEST_CASE("Communicating collision information", "[vehicle]")
{
}

