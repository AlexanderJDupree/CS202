/*
File: food_item.h

Brief: 

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/01/2018
*/

#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include "sstring.h"

class Food_Item
{
  public:

    Food_Item(const char* name = "N/A", int cal = 0, bool vegan = 0, 
              bool gluten_free = 0, bool nuts = 0);

    Food_Item(const Food_Item& origin);

    virtual ~Food_Item();

    virtual void display() const;

    friend  std::ostream& operator << (std::ostream& os, const Food_Item& item);

  protected:

    SString name;

    int calories;

    bool vegan;
    bool gluten_free;
    bool contains_nuts;

    virtual std::ostream& display(std::ostream& os) const;

  private:

};

class Entree : public Food_Item
{
  public:

    Entree(const char* name = "N/A", int cal = 0, bool vegan = 0, 
           bool gluten_free = 0, bool nuts = 0, int proteins = 0, int carbs = 0);

  protected:

    int proteins;
    int carbs;

    std::ostream& display(std::ostream& os) const;
};

#endif // FOOD_ITEM_H

