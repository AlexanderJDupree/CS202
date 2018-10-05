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
#include "vehicle.h" // TODO review
#include "linked_list.h"
#include "traffic_matrix.h"

class Traffic_Manager
{
  public:

    typedef linear_linked_list<Position*> lane;

    // Depth is the length of the road in meters
    Traffic_Manager(unsigned lanes=1, unsigned length=100);

    // Returns true if the street contains no objects
    bool empty() const;

    // Returns the number of lanes on the street
    unsigned lanes() const;

    // Returns the length of the street in meters
    unsigned length() const;

    // Instantiates a vehicle at the specified location
    bool populate(unsigned lane, unsigned distance);

    // Updates each vehicles position in the matrix
    void update();

  protected:

  private:

    const unsigned MAX_LANES;
    const unsigned MAX_LENGTH;
    
    lane* _lanes;

    Traffic_Matrix _matrix;
};

#endif // TRAFFIC_MANAGER_H

