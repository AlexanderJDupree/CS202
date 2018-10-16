/*
File: position.h

Description: Position class acts as the abstract base class for the traffic
             simulation program. The Position abstract class contains virtual 
             methods for update and symbol and concrete methods for determining
             the current position of the object.

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef POSITION_H
#define POSITION_H

class Position
{
  public:

    Position(unsigned lane = 0, unsigned distance = 0);

    virtual ~Position() {};

    // Returns the current lane position
    unsigned lane() const;

    // Returns the current distance travelled
    unsigned distance() const;

    // Updates the position object to handle the collision
    void update_collision(const Position* obj);

    // Pure virtual update. Implemented in derived classes
    virtual Position& update(const Position* obstacle)= 0;

    // Pure virtual symbol. Implemented in derived classes
    virtual const char* symbol() const = 0;

  protected:

    unsigned _lane; // Represents lane position on the street
    unsigned _distance; // Represents the distance travelled along the street

};

#endif // POSITION_H
