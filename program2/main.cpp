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

// Runs menu to examine and manage fleet
void examine_fleet(Fleet_Manager& fleet);

// Runs menu to add a specific type of vehicle to the fleet
void add_vehicle(Fleet_Manager& fleet);

// Generates earnings report from the fleet
void earnings_report(const Fleet_Manager& fleet);

// Examine each individual vehicle in the fleet
void examine_vehicles(Fleet_Manager& fleet);

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
    std::cout << "\n2. Examine each vehicle";
    std::cout << "\n3. Exit";
    std::cout << "\n=========================================================\n";

    switch(Interface::get_input<char>())
    {
        case '1' : add_vehicle(fleet); break;
        case '2' : examine_vehicles(fleet); break;
        case '3' : loop = false; break;
        default : break;
    }
    } while(loop);
}

void add_vehicle(Fleet_Manager& fleet)
{
    Rental_Transport_Factory* factory = NULL;

    std::cout << "\nWhat kind of Rental Tranport is being added to the fleet?";
    std::cout << "\n\n\t1. Electric Scooter\n\t2. Zip Car\n\t3. Rental Bicycle";

    switch(Interface::get_input<char>())
    {
        case '1' : fleet.add_vehicle(factory = new Scooter_Factory); break;
        case '2' : fleet.add_vehicle(factory = new Zip_Car_Factory); break;
        case '3' : fleet.add_vehicle(factory = new Bicycle_Factory); break;
        default : break;
    }

    std::cout << "\nVehicle added!\n";

    Interface::pause_console();

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

void examine_vehicles(Fleet_Manager& fleet)
{
    if (fleet.empty())
    {
        std::cout << "\nThere are no vehicles to examine";
        Interface::pause_console();
        return;
    }

    bool loop = true;
    unsigned counter = 0;

    Fleet_Manager::iterator it = fleet.begin();

    do
    {
        (*it)->display();

        std::cout << 
            "\n1. Next Unit\n2. Previous Unit\n3. Remove Unit\n4. Exit";

        switch(Interface::get_input<char>())
        {
            case '1' : if(counter++ >= fleet.size() - 1)
                       {
                           std::cout << "\nReached end of fleet list.";
                           counter--;
                           Interface::pause_console();
                       }
                       else
                       {
                           it++;
                       }
                       break;

            case '2' : if (counter-- <= 0)
                       {
                           std::cout << "\nReached beginning of fleet list";
                           counter++;
                           Interface::pause_console();
                       }
                       else
                       {
                           it--;
                       }
                       break;
            case '3' : fleet.remove(it);
                       // TODO, figure out off by one error
                       counter = 0;
                       it = fleet.begin();
                       std::cout << "\nUnit removed from fleet.";
                       if (fleet.empty())
                       {
                           loop = false;
                           std::cout << "\nNo more units to display.";
                       }
                       Interface::pause_console();
                       break;
            case '4' : loop = false; break;
        }
        Interface::clear_screen();
    } while (loop);
    return;
}

