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
    : Position(lane, distance, velocity), _friction(.6) {}

int Vehicle::brake_distance() const
{
    return (_velocity * _velocity) / (2 * _friction * GRAVITY_ACCELERATION);
}

Position* Vehicle_Factory::generate(const int& lane, const int& distance)
{
    return new Vehicle(lane, distance);
}

