/*
File: food_item_tests.cpp

Brief: Unit tests for the food_item abstract base class

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/03/2018
*/

#include <catch.hpp>
#include "food_item.h"

class Food_Test_Fixture : public Food_Item
{
  public:

      Food_Test_Fixture(const char* name = "N/A", int cal = 0, bool vegan = 0,
                        bool gluten = 0, bool nuts = 0)
          : Food_Item(name, cal, vegan, gluten, nuts) {}

      std::ostream& display(std::ostream& os) const
      {
          return Food_Item::display(os) << "\nTEST FIXTURE";
      }

};

std::string toString(const Food_Test_Fixture& item)
{
    std::ostringstream oss;

    oss << item;

    return oss.str();
}
TEST_CASE("Constructiong derived Food_Item objects")
{
    SECTION("Default Construction")
    {
        Food_Test_Fixture obj;

        REQUIRE(toString(obj) == 
                "\nN/A"
                "\n================================================="
                "\nCalories: 0"
                "\nVegan: 0"
                "\nGluten Free: 0"
                "\nNuts: 0"
                "\nTEST FIXTURE");
    }
    SECTION("Explicit Construction")
    {
        Food_Test_Fixture item("Food", 100, 1, 1, 1);

        REQUIRE(toString(item) == 
                "\nFood"
                "\n================================================="
                "\nCalories: 100"
                "\nVegan: 1"
                "\nGluten Free: 1"
                "\nNuts: 1"
                "\nTEST FIXTURE");
    }
}

