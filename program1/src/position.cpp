/*
File: position.cpp

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "position.h"

Position::Position(unsigned lane, unsigned distance, unsigned velocity)
    : _lane(lane), _distance(distance), _velocity(velocity) {}

unsigned Position::lane() const
{
    return _lane;
}

unsigned Position::distance() const
{
    return _distance;
}

unsigned Position::velocity() const
{
    return _velocity;
}

void Position::update(unsigned lane, unsigned distance)
{
    _lane = lane;
    _distance = distance;
    return;
}

void Position::accelerate(const int& delta_velocity)
{
    // TODO handle overflow
    _velocity += delta_velocity;
    return;
}

