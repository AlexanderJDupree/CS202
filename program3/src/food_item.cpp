/*
File: food_item.cpp

Brief: 

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/01/2018
*/

#include "food_item.h"

Food_Item::Food_Item(const char* name, int cal, bool vegan, bool gluten,
                     bool nuts)
    : name(name), calories(cal), vegan(vegan), gluten_free(gluten),
      contains_nuts(nuts) {}

Food_Item::Food_Item(const Food_Item& origin)
    : name(origin.name), calories(origin.calories), vegan(origin.vegan), 
      gluten_free(origin.gluten_free), contains_nuts(origin.contains_nuts) {}

Food_Item::~Food_Item() {}

void Food_Item::display() const
{
    std::cout << *this;
}

std::ostream& Food_Item::display(std::ostream& os)  const
{
    os << '\n' << name << '\n' << SString(50, '=') << "\nCalories: " << calories
       << "\nVegan: " << vegan << "\nGluten Free: " << gluten_free << "\nNuts: "
       << contains_nuts;
    return os;
}

std::ostream& operator << (std::ostream& os, const Food_Item& item)
{
    return item.display(os);
}

/****** ENTREE CLASS ******/

Entree::Entree(const char* name, int cal, bool vegan, bool gluten, bool nuts,
               int proteins, int carbs)
    : Food_Item(name, cal, vegan, gluten, nuts), proteins(proteins), carbs(carbs)
{

}

std::ostream& Entree::display(std::ostream& os) const
{
    return os << "\nProteins: " << proteins << "\nCarbs: " << carbs 
              << SString(50, '=');
}

