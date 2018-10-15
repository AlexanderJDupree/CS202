/*
File: player_vehicle.cpp

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "player_vehicle.h"

Player_Vehicle::Player_Vehicle(const int& lane, const int& distance, const int& velocity)
    : Vehicle(lane, distance, velocity) {}

Position& Player_Vehicle::update(const Position* obstacle)
{
    print_status();
    print_menu();

    char input = get_input("\n> ");

    switch(input)
    {
        case '2' : accelerate(5); break;
        case '3' : accelerate(-5); break;
        case '4' : change_lane(_lane - 1); return *this; break;
        case '5' : change_lane(_lane + 1); return *this; break;
        case '6' : accelerate(_velocity * -1); break;
        default : break;
    }

    if((_distance += _velocity) >= obstacle->distance())
    {
        _distance = obstacle->distance() - 1;
    }

    return *this;
}

const char* Player_Vehicle::symbol() const
{
    return "Y";
}

void Player_Vehicle::change_lane(const int& lane)
{
    if (lane < 4 && lane >= 0)
    {
        _lane = lane;
    }
    return;
}

void Player_Vehicle::accelerate(const int& delta_velocity)
{
    // Handle underflow
    if (_velocity + delta_velocity < 0)
    {
        _velocity = 0;
    }
    _velocity += delta_velocity;
    return;
}

void Player_Vehicle::print_status() const
{
    std::cout << "\nYou are in lane " << _lane + 1 << " travelling at " << _velocity
              << "m/s.";
    return;
}

void Player_Vehicle::print_menu() const
{
    std::cout << "\n1. Continue\t2. Accelerate\t3. Decelerate"
              << "\n4. Move Left\t5.Move Right\t6. Stop";
    std::cout << std::endl;
    return;
}

char Player_Vehicle::get_input(const char* prompt) const
{
    char input;

    std::cout << prompt;
    std::cin >> input;

    return input;
}

