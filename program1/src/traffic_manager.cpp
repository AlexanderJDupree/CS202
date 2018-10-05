/*
File: traffic_manager.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "traffic_manager.h"

Traffic_Manager::Traffic_Manager(unsigned lanes, unsigned length)
    : MAX_LANES(lanes), MAX_LENGTH(length), _lanes(new lane[MAX_LANES]),
      _matrix(MAX_LANES, MAX_LENGTH) {}

bool Traffic_Manager::empty() const
{
    for (unsigned i = 0; i < MAX_LANES; ++i)
    {
        // If ANY lane contains an object then the street is not empty
        if(!_lanes[i].empty())
        {
            return false;
        }
    }
    return true;
}

unsigned Traffic_Manager::lanes() const
{
    return MAX_LANES;
}

unsigned Traffic_Manager::length() const
{
    return MAX_LENGTH;
}

bool Traffic_Manager::populate(unsigned lane, unsigned distance)
{
    if (lane >= MAX_LANES || distance >= MAX_LENGTH)
    {
        // TODO throw custom exception
        return false;
    }

    _lanes[lane].push_front(new Vehicle(lane, distance, 0));

    return true;
}

void Traffic_Manager::update()
{
    for (unsigned i = 0; i < MAX_LANES; ++i)
    {
        for (lane::iterator it = _lanes[i].begin(); !it.null(); ++it)
        {
            //_matrix.update(*it);
        }
    }
}

