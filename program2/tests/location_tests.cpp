/*
File: location_tests.cpp

Description: Unit tests for the location class

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include <catch.hpp>
#include "location.h"

std::string toString(const Location& location)
{
    std::ostringstream oss;

    oss << location;

    return oss.str();
}

TEST_CASE("Constructing location objects", "[constructors], [location]")
{
    SECTION("Default construction")
    {
        Location location;

        REQUIRE(toString(location) == "N/A and N/A");
    }
    SECTION("Copy Construction")
    {
        Location origin("4th", "Harrison");

        Location copy(origin);

        REQUIRE(copy == origin);
    }
}

