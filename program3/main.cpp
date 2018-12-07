/*
File: main.cpp

Brief: main.cpp acts as the entry point for this application. File also contains
       basic UI methods for displaying menu options and directing input.

Author: Alexander DuPree

Class: CS202

Assignment: program 3

Date: 11/01/2018
*/

#include "interface.h"
#include "food_menu.h"

typedef circular_linked_list<Food_Item*> Food_Order;

void intro();

// Prints main menu to console
void print_menu();

// Runs application, loops until user exits
void run();

// runs menu to examine food menu
void examine_menu(Food_Menu& menu, Food_Order& order);

// Adds a new food item to the menu
void append_menu(Food_Menu& menu);

// Examines each food item individually
void examine_food_items(Food_Menu& menu, Food_Order& order);

// Examines the clients order
void examine_order(Food_Order& order);

// Builds a predefined menu
void build_menu(Food_Menu& menu);

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
    Food_Order order;

    build_menu(menu);

    bool loop = true;

    do
    {

    print_menu();
    switch(Interface::get_input<char>())
    {
        case '1' : examine_menu(menu, order); break;
        case '2' : examine_order(order); break;
        case '3' : loop = false; break;
        default : break;
    }
    Interface::clear_screen();

    } while(loop);

    return;
}

void examine_menu(Food_Menu& menu, Food_Order& order)
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
        case '1' : append_menu(menu); break;
        case '2' : examine_food_items(menu, order); break;
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
        case '1' : menu += (factory = new Entree_Factory); break;
        case '2' : menu += (factory = new Dessert_Factory); break;
        case '3' : menu += (factory = new Beverage_Factory); break;
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

void examine_food_items(Food_Menu& menu, Food_Order& order)
{
    bool loop = true;
    unsigned counter = 0;

    Food_Menu::iterator it = menu.begin();

    std::cout << "\n\tItems are ordered by calorie count";

    do
    {
        std::cout << *(*it);

        std::cout <<
            "\n1. Add item to order    2. Next menu item    3. Exit";

        switch(Interface::get_input<char>())
        {
            case '1' : order.push_back(*it);
                       std::cout << "\n" << (*it)->dish_name() 
                                 << " was added to your order!\n";
                       Interface::pause_console();
                       break;

            case '2' : if (counter++ >= menu.size() - 1)
                       {
                           std::cout << "\nReached end of menu!";
                           loop = false;
                           Interface::pause_console();
                       }
                       else
                       {
                           ++it;
                       }
                       break;

            case '3' : loop = false; break;
        }
    } while (loop);
    return;
}

void examine_order(Food_Order& order)
{
    if (order.empty())
    {
        std::cout << "\nYou haven't orderd anything yet!";
    }
    else
    {
        int total_calories = 0;
        Food_Order::const_iterator it = order.begin();

        Interface::clear_screen();
        do 
        {
            total_calories += (*it)->total_calories();

            std::cout << '\n' << (*it)->dish_name() << ": " 
                      << (*it)->total_calories() << " cal";

        } while(++it != order.end());

        std::cout << "\n\nNumber of Items: " << order.size();
        std::cout << "\nTotal Calories: " << total_calories;
    }

    Interface::pause_console();
}

void build_menu(Food_Menu& menu)
{
    menu.insert(350, new Entree("Carne Asada Tacos", 350, 0, 0, 0, 45, 25));
    menu.insert(280, new Entree("Chicken Enchiladas", 280, 0, 0, 0, 45, 45));
    menu.insert(245, new Entree("Vegan Torta", 245, 1, 1, 0, 35, 42));

    menu.insert(490, new Dessert("Flan", 490, 1, 1, 0, 38));
    menu.insert(420, new Dessert("Vegan Ice Cream", 420, 1, 1, 1, 31));

    menu.insert(101, new Beverage("Corona", 101, 0, 1, 0, 0, 1));
    menu.insert(156, new Beverage("Horchata", 156, 0, 0, 1, 23, 0));
    return;
}

