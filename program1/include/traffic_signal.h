/*
File: traffic_signal.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef TRAFFIC_SIGNAL_H
#define TRAFFIC_SIGNAL_H

#include "position.h"

class Traffic_Signal : public Position
{
  public:

    Traffic_Signal(unsigned lane=0, unsigned distance=0);

    Position& update(const Position* obstacle);

    const char* symbol() const;

};

#endif // TRAFFIC_SIGNAL_H

