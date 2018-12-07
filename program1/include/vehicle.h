/*
File: vehicle.h

Description: Vehicle is derived from the Position abstract base class and 
             implements the required pure virtual methods declared by the base
             class. Vehicle is a position object but also manages it's position
             with the added dimension of velocity. The new position is calculated
             with the current velocity everytime the update method is called. 

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

      // Assess collision and adjust position if the obstacle is too close. 
      Position& update(const Position* obstacle);

      // Returns a 'C' to represent the Vehicle
      const char* symbol() const;

  protected:

      unsigned _velocity; // Represents the speed of the vehicle in m/s
};

#endif // VEHICLE_H

