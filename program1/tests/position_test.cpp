/*
File: position_test.h

Description: Unit tests for Position base class

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include <catch.hpp>
#include "position.h"

TEST_CASE("Constructing position objects", "[position], [constructors]")
{
    SECTION("Default Construction")
    {
        Position pos;

        REQUIRE(pos.lane() == 0);
        REQUIRE(pos.distance() == 0);
    }
    SECTION("Explicit construction")
    {
        Position pos(1, 3);

        REQUIRE(pos.lane() == 1);
        REQUIRE(pos.distance() == 3);
    }
}

