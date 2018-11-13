/*
File: main.cpp

Brief: 

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/01/2018
*/

#include "interface.h"
#include "food_menu.h"

void intro();

// Prints main menu to console
void print_menu();

// Runs application, loops until user exits
void run();

// runs menu to examine food menu
void examine_menu(Food_Menu& menu);

// Adds a new food item to the menu
void append_menu(Food_Menu& menu);

int main()
{
    intro();

    run();

    return 0;
}

void intro()
{
    std::cout <<
    "========================================================================"
    "\n"
    "\n"
    "\n"
    "\n"
    "\n                              Program 3"
    "\n"
    "\n"
    "\n                      Author: Alexander DuPree"
    "\n"
    "\n"
    "\n"
    "=======================================================================\n";

    Interface::pause_console();
    Interface::clear_screen();

    return;
}

void print_menu()
{

    std::cout << "=========================================================\n";
    std::cout << "1. Examine Menu\n2. Check Your Order\n"
              << "3. Exit Application";
    std::cout << "\n=========================================================\n";
    return;
}

void run()
{
    Food_Menu menu;

    bool loop = true;

    do
    {

    print_menu();
    switch(Interface::get_input<char>())
    {
        case '1' : examine_menu(menu); break;
        case '2' : break;
        case '3' : loop = false; break;
        default : break;
    }
    Interface::clear_screen();

    } while(loop);

    return;
}

void examine_menu(Food_Menu& menu)
{
    bool loop = true;

    do
    {

    Interface::clear_screen();
    std::cout << "\nNumber of Food Items: " << menu.size();
    std::cout << "\n=========================================================";
    std::cout << "\n1. Add new food item";
    std::cout << "\n2. Examine each food item";
    std::cout << "\n3. Exit";
    std::cout << "\n=========================================================\n";

    switch(Interface::get_input<char>())
    {
        case '1' : append_menu(menu);
        case '2' : break;
        case '3' : loop = false; break;
        default : break;
    }
    } while(loop);
}

void append_menu(Food_Menu& menu)
{
    Food_Item_Factory* factory = NULL;

    std::cout << "\nWhat kind of food item is being added to the menu?";
    std::cout << "\n\n\t1. Entree\n\t2. Dessert\n\t3. Beverage";

    switch(Interface::get_input<char>())
    {
        case '1' : menu.add_item(factory = new Entree_Factory); break;
        case '2' : menu.add_item(factory = new Dessert_Factory); break;
        case '3' : menu.add_item(factory = new Beverage_Factory); break;
        default : break;
    }

    if (!factory)
    {
        std::cout << "\nNo selection made, item was not added to the menu\n";
    }
    else
    {
        std::cout << "\nItem was added to the menu!\n";
    }

    Interface::pause_console();

    delete factory;
    return;
}

