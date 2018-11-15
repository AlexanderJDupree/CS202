/*
File: food_menu.cpp

Brief: Implementation file for the Food_Menu derived class. Defines methods for 
       destruction and instantiation of food item objects via factory objects

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/03/2018
*/

#include "food_menu.h"

Food_Menu::~Food_Menu()
{
    clear_item functor;

    postorder_traversal(_root, functor);

    return;
}

Food_Menu& Food_Menu::add_item(const Food_Item_Factory* factory)
{
    Food_Item* temp = factory->create();
    insert(temp->total_calories(), temp);
    return *this;
}

Food_Menu& Food_Menu::operator += (const Food_Item_Factory* factory)
{
    return add_item(factory);
}

