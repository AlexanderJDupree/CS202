/*
File: fleet_manager.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "fleet_manager.h"

Fleet_Manager::Fleet_Manager() {}

Fleet_Manager::~Fleet_Manager()
{
    for (Fleet::iterator it = fleet.begin(); it != fleet.end(); ++it)
    {
        delete *it;
    }
}

int Fleet_Manager::size() const
{
    return fleet.size();
}

void Fleet_Manager::add_vehicle(Rental_Transport_Factory* factory)
{
    fleet.push_back(factory->create());
}

void Fleet_Manager::display_earnings() const
{   
    Fleet::const_iterator min = fleet.begin();
    Fleet::const_iterator max = fleet.begin();

    float total = 0.0;
    float average = 0.0;

    for (Fleet::const_iterator it = fleet.begin(); it != fleet.end(); ++it)
    {
        total += (*it)->earnings(); 

        if ((*it)->earnings() < (*min)->earnings())
        {
            min = it;
        }
        if ((*it)->earnings() > (*max)->earnings())
        {
            max = it;
        }
    }

    if (!min.null())
    {
        std::cout << "\n\nLowest Earner: $" << (*min)->earnings();
        (*min)->display();
        std:: cout << "\n\nHighest Earner: $" << (*max)->earnings();
        (*max)->display();

        average = total / fleet.size();
    }

    std::cout << "\nTotal Earnings: $" << total;
    std::cout << "\nAverage Earnings: $" << average;
}

