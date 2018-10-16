/*
File: main.cpp

Description: main.cpp acts as the entry point for the program 1 application
             This file contains methods to clear the screen, print messages,
             and populate objects with the traffic_manager object.

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "traffic_manager.h"

// Populates player and vehicle objects for simulation
void populate_street(Traffic_Manager& street);

// Runs the simulation until player reaches end of street
void run_simulation(Traffic_Manager& street);

void print_message(const char* message);

void clear_screen();

int main()
{
    Traffic_Manager street(4, 100);

    populate_street(street);

    run_simulation(street);

    return 0;
}

void populate_street(Traffic_Manager& street)
{
    street.player_populate(2, 0, 10);
    street.populate(0, 5, 10);
    street.populate(1, 7, 8);
    street.populate(3, 20, 7);
    return;
}

void run_simulation(Traffic_Manager& street)
{
    do {
        clear_screen();
        street.display();
    } while(street.update());

    street.display();

    print_message("Congratulations you made it to the end of the street!");

    return;
}

void print_message(const char* message)
{
    std::cout << '\n' << message << std::endl;
    return;
}

void clear_screen()
{
    for (unsigned i = 0; i < 100; ++i)
    {
        std::cout << '\n';
    }
    return;
}

