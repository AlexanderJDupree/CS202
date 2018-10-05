/*
File: position.h

Description: 

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

    Position(unsigned lane = 0, unsigned distance = 0, unsigned velocity = 0);

    unsigned lane() const;
    unsigned distance() const;
    unsigned velocity() const;

    void update(unsigned lane, unsigned distance);

    void accelerate(const int& delta_velocity);

  protected:

    unsigned _lane;
    unsigned _distance;
    unsigned _velocity;

  private:

};

class Position_Factory
{
  public:

    virtual Position* generate(const int& x, const int& y)=0;
};

#endif // POSITION_H
