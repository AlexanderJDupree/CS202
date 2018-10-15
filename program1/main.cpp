/*
File: main.cpp

Description: main.cpp acts as the entry point for the program 1 application

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
    //street.populate(0, 0, 14);
    street.populate(1, 7, 8);
   // street.populate(1, 2, 8);
    street.populate(3, 20, 7);
    //street.populate(3, 0, 14);
    return;
}

void run_simulation(Traffic_Manager& street)
{
    do {
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

