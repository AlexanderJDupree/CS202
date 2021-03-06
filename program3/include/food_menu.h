/*
File: food_menu.h

Brief: Food Menu is a specialized version of the templated binary search tree 
       class. The Food Menu holds a upcasted Food Item objects, these objects
       are sorted by caloric values. The Food Menu can instantiate objects with
       factories or receive pointers to food item objects. The Food Menu WILL 
       deallocate all food item objects on the menu upon destruction. 

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/03/2018
*/

#ifndef FOOD_MENU_H
#define FOOD_MENU_H

#include "food_item.h"
#include "binary_search_tree.h"

class Food_Menu : public binary_tree<int, Food_Item*>
{
  public:

    ~Food_Menu();

    // Adds a new food_item object to the menu
    Food_Menu& add_item(const Food_Item_Factory* factory);

    Food_Menu& operator += (const Food_Item_Factory* factory);

  private:

    // Used in the destructor to deallocate food item objects
    struct clear_item
    {
        void operator() (b_node*& leaf)
        {
            delete leaf->value();
            leaf->value() = NULL;
            return;
        }
    };

};

#endif // FOOD_MENU_H

