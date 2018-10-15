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

    Position(unsigned lane = 0, unsigned distance = 0);

    virtual ~Position() {};

    unsigned lane() const;
    unsigned distance() const;

    void update_collision(const Position* obj);

    virtual Position& update(const Position* obstacle)= 0;

    virtual const char* symbol() const = 0;

  protected:

    unsigned _lane;
    unsigned _distance;

  private:

};

class Position_Factory
{
  public:

    virtual Position* generate() = 0;
};

#endif // POSITION_H
