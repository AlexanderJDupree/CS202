/*
File: vehicle.cpp

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "vehicle.h"


Vehicle::Vehicle(const int& lane, const int& distance, const int& velocity)
    : Position(lane, distance), _velocity(velocity) {}

Position& Vehicle::update(const Position* obstacle)
{
    // Nearest obstacle is in path, decelerate and brake
    if ((_distance += _velocity) >= obstacle->distance())
    {
        _distance = obstacle->distance() - 1;
    }

    return *this;
}

const char* Vehicle::symbol() const
{
    return "C";
}

