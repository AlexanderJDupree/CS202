/*
File: traffic_manager.h

Description: Traffic Manager acts as the overseer for all position objects in 
             the system. At its is an array of linear linked list where each
             index in the array contains a linear linked list of vehicles in 
             that lane. Complementing this data structure is the traffic_matrix
             class which helps display and manage position updates of each 
             position object in the system. 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef TRAFFIC_MANAGER_H
#define TRAFFIC_MANAGER_H

#include "linked_list.h"
#include "player_vehicle.h"
#include "traffic_signal.h"
#include "traffic_matrix.h"

class Traffic_Manager
{
  public:

    typedef linear_linked_list<Position*> lane;

    // Depth is the length of the road in meters
    Traffic_Manager(unsigned lanes=1, unsigned length=100);

    ~Traffic_Manager();

    // Returns true if the street contains no objects
    bool empty() const;

    // Returns the number of lanes on the street
    unsigned lanes() const;

    // Returns the length of the street in meters
    unsigned length() const;

    // Instantiates a vehicle at the specified location
    bool populate(unsigned lane, unsigned distance, unsigned velocity=0);

    // Instantiates a player vehicle object at the specified location
    bool player_populate(unsigned lane, unsigned distance, unsigned velocity);

    // Updates each vehicles position in the matrix
    bool update();

    // Displays the graphical representation of the street
    void display() const;

  private:

    const unsigned MAX_LANES;
    const unsigned MAX_LENGTH;
    
    // Array of linear linked list, each index represents a lane in the road
    lane* _lanes;

    // Traffic Matrix object is used for display and update methods
    Traffic_Matrix _matrix;

};

#endif // TRAFFIC_MANAGER_H

