/*
File: matrix_test.h

Description: Unit tests for Street Matrix class

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include <catch.hpp>
#include "traffic_matrix.h"

TEST_CASE("Constructing Traffic Matrices", "[traffic_matrix], [constructors]")
{
    SECTION("Default Construction")
    {
        Traffic_Matrix matrix;

    }
    SECTION("Explicit Construction")
    {
        Traffic_Matrix matrix(4, 100);

    }
}

TEST_CASE("Populating the traffic matrix with vehicle objects", "[traffic_matrix], [insert]")
{

}

