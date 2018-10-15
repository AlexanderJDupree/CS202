/*
File: vehicle.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include "position.h"

class Vehicle : public Position
{
  public:

      Vehicle(const int& lane=0, const int& distance=0, const int& velocity=0);

      Position& update(const Position* obstacle);

      const char* symbol() const;

  protected:

      unsigned _velocity;
};

#endif // VEHICLE_H

