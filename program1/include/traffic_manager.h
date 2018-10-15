/*
File: traffic_manager.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef TRAFFIC_MANAGER_H
#define TRAFFIC_MANAGER_H

#include "position.h"
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

    bool player_populate(unsigned lane, unsigned distance, unsigned velocity);

    // Updates each vehicles position in the matrix
    bool update();

    // Displays the graphical representation of the street
    void display() const;

  protected:

  private:

    const unsigned MAX_LANES;
    const unsigned MAX_LENGTH;
    
    lane* _lanes;

    Traffic_Matrix _matrix;

    // Updates the player's vehicle to be inserted into the correct lane
    void update_lane_position(Position* player);
};

#endif // TRAFFIC_MANAGER_H

