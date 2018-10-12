/*
File: vehicle.cpp

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "vehicle.h"

const float Vehicle::GRAVITY_ACCELERATION = 9.83;

Vehicle::Vehicle(const int& lane, const int& distance, const int& velocity)
    : Position(lane, distance), _velocity(velocity), _friction(.6) {}

int Vehicle::brake_distance() const
{
    return (_velocity * _velocity) / (2 * _friction * GRAVITY_ACCELERATION);
}

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

