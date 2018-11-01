/*
File: fleet_manager.h

Description:

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/23/2018
*/

#include "fleet_manager.h"

Fleet_Manager::Fleet_Manager()
    : double_linked_list<Rental_Transport*>() {}

Fleet_Manager::~Fleet_Manager()
{
    Node* temp = head;
    while (temp)
    {
        delete temp->data();
        temp = temp->next();
    }
}

void Fleet_Manager::add_vehicle(Rental_Transport_Factory* factory)
{
    push_back(factory->create());
}

void Fleet_Manager::display_earnings() const
{   
    const_iterator min = begin();
    const_iterator max = begin();

    float total = 0.0;
    float average = 0.0;

    for (const_iterator it = begin(); it != end(); ++it)
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

        average = total / _size;
    }

    std::cout << "\nTotal Earnings: $" << total;
    std::cout << "\nAverage Earnings: $" << average;
}

