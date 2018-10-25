/*
File: main.cpp

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "interface.h"
#include "fleet_manager.h"

void intro();

// Prints main menu to console
void print_menu();

// Runs application, loops until user exits
void run();

void examine_fleet(Fleet_Manager& fleet);
void add_vehicle(Fleet_Manager& fleet);
void earnings_report(const Fleet_Manager& fleet);

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
    "\n                              Program 4"
    "\n"
    "\n"
    "\n                      Author: Alexander DuPree"
    "\n"
    "\n"
    "\n"
    "=======================================================================\n";

    Interface::pause_console();
    Interface::clear_screen();

    std::cout << 
        "Welcome to the fleet manager application! This application"
        "\nallows you to manage the status and even generate revenue"
        "\nreports from your fleet of rental transportation vehicles."
        "\n";

    return;
}

void print_menu()
{

    std::cout << "=========================================================\n";
    std::cout << "1. Examine Fleet\n2. Generate Earnings Report\n"
              << "3. Exit Application";
    std::cout << "\n=========================================================\n";
    return;
}

void run()
{
    Fleet_Manager fleet;

    bool loop = true;

    do
    {

    print_menu();
    switch(Interface::get_input<char>())
    {
        case '1' : examine_fleet(fleet); break;
        case '2' : earnings_report(fleet); break;
        case '3' : loop = false; break;
        default : break;
    }
    Interface::clear_screen();

    } while(loop);

    return;
}

void examine_fleet(Fleet_Manager& fleet)
{
    bool loop = true;

    do
    {

    Interface::clear_screen();
    std::cout << "\nNumber of Rental Transportation Vehicles: " << fleet.size();
    std::cout << "\n=========================================================";
    std::cout << "\n1. Add new vehicle";
    std::cout << "\n2. Exit";
    std::cout << "\n=========================================================\n";

    switch(Interface::get_input<char>())
    {
        case '1' : add_vehicle(fleet); break;
        case '2' : loop = false; break;
        default : break;
    }
    } while(loop);
}

void add_vehicle(Fleet_Manager& fleet)
{
    Rental_Transport_Factory* factory = NULL;

    std::cout << "\nWhat kind of Rental Tranport is being added to the fleet?";
    std::cout << "\n\n\t1. Electric Scooter";

    switch(Interface::get_input<char>())
    {
        case '1' : fleet.add_vehicle(factory = new Scooter_Factory);
        default : break;
    }

    std::cout << "\nVehicle added!";

    delete factory;
    return;
}

void earnings_report(const Fleet_Manager& fleet)
{
    std::cout << 
        "\nEarnings is calculated by the per mile rate of each vehicle and the"
        "\ntotal miles used.";
    
    fleet.display_earnings();

    Interface::pause_console();

    return;
}

