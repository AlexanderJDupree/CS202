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

      // Returns the distance required to brake to a stop in meters
      int brake_distance() const; 

      Position& update(const Position* obstacle);

      const char* symbol() const;

  protected:

      unsigned _velocity;

  private:

      static const float GRAVITY_ACCELERATION; // Used to calc brake distance
      const float _friction; // Used to calculate brake distance

};

#endif // VEHICLE_H

