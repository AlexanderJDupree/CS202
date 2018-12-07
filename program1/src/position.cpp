/*
File: position.cpp

Description: Implementation file for the Position abstract base class. Defines
             basic methods for construction and location information. 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "position.h"

Position::Position(unsigned lane, unsigned distance)
    : _lane(lane), _distance(distance) {}

unsigned Position::lane() const
{
    return _lane;
}

unsigned Position::distance() const
{
    return _distance;
}

void Position::update_collision(const Position* obj)
{
    _distance = obj->distance() - 1;
    return;
}

