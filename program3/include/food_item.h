/*
File: food_item.h

Brief:  Food Item acts as the abstract base class for all objects in the 
        hierarchy. Food Item base class manages all common attributes relevant 
        to an item of food. Food Item defines virtual methods as well as have
        its comparison operators overloaded to compare calorie counts.

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

    // Default constructor assigns null equivalent values
    Food_Item(const char* name = "N/A", int cal = 0, bool vegan = 0, 
              bool gluten_free = 0, bool nuts = 0);

    // Copy Constructor
    Food_Item(const Food_Item& origin);

    // Virtual Destructor is undefined as Food Item does not manage any resources
    virtual ~Food_Item();

    // Displays all attributes in a readable format
    virtual void display() const;

    // Returns the name of the food item
    const SString& dish_name() const;

    int total_calories() const;

    bool operator == (const Food_Item& rhs) const;
    bool operator != (const Food_Item& rhs) const;
    bool operator <  (const Food_Item& rhs) const;
    bool operator <= (const Food_Item& rhs) const;
    bool operator >  (const Food_Item& rhs) const;
    bool operator >= (const Food_Item& rhs) const;

    friend  std::ostream& operator << (std::ostream& os, const Food_Item& item);

  protected:

    SString name;

    int calories;

    bool vegan; 
    bool gluten_free;
    bool contains_nuts;

    virtual std::ostream& display(std::ostream& os) const;

  private:

    // Returns "Yes" or "No" based on flags status
    const char* print_status (bool flag) const;

};

class Entree : public Food_Item
{
  public:

    Entree(const char* name = "N/A", int cal = 0, bool vegan = 0, 
           bool gluten_free = 0, bool nuts = 0, int proteins = 0, int carbs = 0);

    Entree(const Entree& origin);

  protected:

    int proteins;
    int carbs;

    std::ostream& display(std::ostream& os) const;
};

class Dessert : public Food_Item
{
  public:

    Dessert(const char* name = "N/A", int cal = 0, bool vegan = 0,
            bool gluten_free = 0, bool nuts = 0, int sugars = 0);

    Dessert(const Dessert& origin);

  protected:

    int sugars;

    virtual std::ostream& display(std::ostream& os) const;

};

class Beverage : public Dessert
{
  public:

    Beverage(const char* name = "N/A", int cal = 0, bool vegan = 0, 
             bool gluten_free = 0, bool nuts = 0, int sugars = 0, bool alcohol = 0);

    Beverage(const Beverage& origin);

  protected:

    bool alcoholic;

    std::ostream& display(std::ostream& os) const;

};

/****** FOOD_ITEM FACTORIES ******/

class Food_Item_Factory
{
  public:

      virtual ~Food_Item_Factory() {} 

      // Returns a new Food_Item object
      virtual Food_Item* create() const = 0;
};

class Entree_Factory : public Food_Item_Factory
{
  public:

      Food_Item* create() const;
};

class Dessert_Factory : public Food_Item_Factory
{
  public:

      Food_Item* create() const;
};

class Beverage_Factory : public Food_Item_Factory
{
  public:

      Food_Item* create() const;
};

#endif // FOOD_ITEM_H

