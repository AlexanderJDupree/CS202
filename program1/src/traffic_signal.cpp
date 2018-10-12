/*
File: traffic_signal.cpp

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "traffic_signal.h"

Traffic_Signal::Traffic_Signal(unsigned lane, unsigned distance)
    : Position(lane, distance) {}

Position& Traffic_Signal::update(const Position* obstacle)
{
    if(obstacle)
    {
        return *this;
    }
    return *this;
}

const char* Traffic_Signal::symbol() const
{
    return "|";
}

