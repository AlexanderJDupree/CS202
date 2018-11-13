/*
File: food_item.cpp

Brief: 

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/01/2018
*/

#include "interface.h"
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

int Food_Item::total_calories() const
{
    return calories;
}

std::ostream& Food_Item::display(std::ostream& os)  const
{
    os << '\n' << name << '\n' << SString(50, '=') << "\nCalories: " << calories
       << "\nVegan: " << vegan << "\nGluten Free: " << gluten_free << "\nNuts: "
       << contains_nuts;
    return os;
}

bool Food_Item::operator==(const Food_Item& rhs) const
{
    return name == rhs.name && calories == rhs.calories;
}
bool Food_Item::operator != (const Food_Item& rhs) const
{
    return !(*this == rhs);
}
bool Food_Item::operator <  (const Food_Item& rhs) const
{
    return calories < rhs.calories;
}
bool Food_Item::operator <= (const Food_Item& rhs) const
{
    return (*this == rhs) || (*this < rhs);
}
bool Food_Item::operator >  (const Food_Item& rhs) const
{
    return !(*this < rhs);
}
bool Food_Item::operator >= (const Food_Item& rhs) const
{
    return (*this == rhs) || (*this > rhs);
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

Entree::Entree(const Entree& origin)
    : Food_Item(origin), proteins(origin.proteins), carbs(origin.carbs) {}

std::ostream& Entree::display(std::ostream& os) const
{
    return Food_Item::display(os) << "\nProteins: " << proteins << "\nCarbs: " 
                                  << carbs << SString(50, '=');
}

/****** DESSERT CLASS ******/

Dessert::Dessert(const char* name, int cal, bool vegan, bool gluten, bool nuts, 
                 int sugars)
    : Food_Item(name, cal, vegan, gluten, nuts), sugars(sugars) {}

Dessert::Dessert(const Dessert& origin)
    : Food_Item(origin), sugars(origin.sugars) {}

std::ostream& Dessert::display(std::ostream& os) const
{
    return Food_Item::display(os) << "\nSugars: " << sugars << SString(50, '=');
}

/****** BEVERAGE CLASS ******/

Beverage::Beverage(const char* name, int cal, bool vegan, bool gluten, bool nuts,
                   int sugars, bool alcohol)
    : Dessert(name, cal, vegan, gluten, nuts, sugars), alcoholic(alcohol) {}

Beverage::Beverage(const Beverage& origin)
    : Dessert(origin), alcoholic(origin.alcoholic) {}

std::ostream& Beverage::display(std::ostream& os) const
{
    return Food_Item::display(os) << "\nSugars: " << sugars << "\nAlcoholic: " 
                                  << alcoholic << SString(50, '=');
}

/****** FOOD_ITEM FACTORIES ******/

Food_Item* Entree_Factory::create() const
{
    return new Entree(
            Interface::get_input<SString>("\nEnter the name of the entree: "),
            Interface::get_input<int>("\nEnter total calories for the dish: "),
            Interface::get_bool("\nIs this dish vegan?"),
            Interface::get_bool("\nIs this dish gluten_free?"),
            Interface::get_bool("\nDoes this dish contain nuts?"),
            Interface::get_input<int>("\nEnter protein count (grams): "),
            Interface::get_input<int>("\nEnter total carbs (grams): ")
            );
}

Food_Item* Dessert_Factory::create() const
{
    return new Dessert(
            Interface::get_input<SString>("\nEnter the name of the Dessert: "),
            Interface::get_input<int>("\nEnter total calories: "),
            Interface::get_bool("\nIs this dessert vegan?"),
            Interface::get_bool("\nIs this dessert gluten_free?"),
            Interface::get_bool("\nDoes the dessert contain nuts?"),
            Interface::get_input<int>("\nEnter total sugars (grams): ")
            );
}

Food_Item* Beverage_Factory::create() const
{
    return new Beverage(
            Interface::get_input<SString>("\nEnter the name of the beverage: "),
            Interface::get_input<int>("\nEnter total calories: "),
            Interface::get_bool("\nIs this Beverage vegan?"),
            Interface::get_bool("\nIs this Beverage gluten_free?"),
            Interface::get_bool("\nDoes the Beverage contain nuts?"),
            Interface::get_input<int>("\nEnter total sugars (grams): "),
            Interface::get_bool("\nIs this Beverage alcoholic?")
            );
}

