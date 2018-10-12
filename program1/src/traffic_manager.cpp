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
      _matrix(MAX_LANES, MAX_LENGTH) 
{
    for (unsigned i = 0; i < MAX_LANES; ++i)
    {
        _lanes[i].push_back(new Traffic_Signal(i, MAX_LENGTH - 1));
    }
}

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

bool Traffic_Manager::populate(unsigned lane, unsigned distance, unsigned velocity)
{
    if (lane >= MAX_LANES || distance >= MAX_LENGTH)
    {
        // TODO throw custom exception
        return false;
    }

    _lanes[lane].push_front(new Vehicle(lane, distance, velocity));

    // TODO review how to handle multiple objects populated into same index
    return _matrix.insert(*_lanes[lane].begin());
}

bool Traffic_Manager::player_populate(unsigned lane, unsigned distance, unsigned velocity)
{
    if (lane >= MAX_LANES || distance >= MAX_LENGTH)
    {
        return false;
    }

    _lanes[lane].push_front(new Player_Vehicle(lane, distance, velocity));

    return _matrix.insert(*_lanes[lane].begin());
}

void Traffic_Manager::update()
{
    for (unsigned i = 0; i < MAX_LANES; ++i)
    {
        for (lane::iterator it = _lanes[i].begin(); !it.null(); ++it)
        {
            lane::iterator iter = it;

            if ((++iter).null())
            {
                _matrix.update(*it, NULL);
            }
            else
            {
                _matrix.update(*it, *iter);
            }
        }
    }
}

void Traffic_Manager::display() const
{
    _matrix.display();
    return;
}

