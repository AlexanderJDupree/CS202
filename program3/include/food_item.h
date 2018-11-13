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

