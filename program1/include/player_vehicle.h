/*
File: player_vehicle.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef PLAYER_VEHICLE_H
#define PLAYER_VEHICLE_H

#include <iostream>
#include "vehicle.h"

class Player_Vehicle : public Vehicle
{
  public:

    Player_Vehicle(const int& lane=0, const int& distance=0, const int& velocity=0);

    Position& update(const Position* obstacle);

    const char* symbol() const;

    void change_lane(const int& lane);

    void accelerate(const int& delta_velocity);

  protected:

  private:

    void print_menu() const;
    char get_input(const char* prompt) const;

};

#endif // PLAYER_VEHICLE_H

