/*
File: player_vehicle.h

Description: Player Vehicle is derived from the Vehicle class. The Player vehicle
             operates as the interface for the user to manipulate a vehicle
             through the traffic_manager program. The Player Vehicle operates 
             under the same principles as the Vehicle class however, it's update
             method is used to read in and evaluate user input. 

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

    // Reads in user input and evaluates new position based on input
    Position& update(const Position* obstacle);

    // Prints the ASCII representaion of the player vehicle
    const char* symbol() const;

  private:

    // Changes to the deisred lane
    void change_lane(const int& lane);

    // Applies the change of velocity to the velocity member
    void accelerate(const int& delta_velocity);

    // Prints the player vehicles status to console
    void print_status() const;

    // Prints the user menu
    void print_menu() const;

    // Grabs input from the user
    char get_input(const char* prompt) const;

};

#endif // PLAYER_VEHICLE_H

