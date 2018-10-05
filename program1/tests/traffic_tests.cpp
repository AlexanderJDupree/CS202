/*
File: traffic_tests.h

Description: Unit tests for Street map class

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include <catch.hpp>
#include "traffic_manager.h"
#include "vehicle.h"

TEST_CASE("Constructing Traffic_Manager objects", "[traffic_manager], [constructors]")
{
    SECTION("Default Construction")
    {
        Traffic_Manager street;

        REQUIRE(street.empty());
    }
    SECTION("Explicit Construction")
    {
        Traffic_Manager street(4, 1000);

        REQUIRE(street.lanes() == 4);
        REQUIRE(street.length() == 1000);
    }
}

TEST_CASE("Populating a street with vehicle objects", "[traffic_manager], [insert]")
{
    Traffic_Manager street(4, 1000);

    SECTION("Adding a single vehicle")
    {
        REQUIRE(street.populate(0,0));
    }
    SECTION("Populating a vehicle with incorrect bounds")
    {
        REQUIRE_FALSE(street.populate(5, 1001));
    }

}

