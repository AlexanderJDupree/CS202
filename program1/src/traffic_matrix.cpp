/*
File: traffic_matrix.h

Description: 

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#include "traffic_matrix.h"

Traffic_Matrix::Traffic_Matrix(unsigned lanes, unsigned length)
    : MAX_LANES(lanes), MAX_LENGTH(length), _matrix(new Position**[MAX_LANES])
{
    // Initializes each location in the matrix to NULL
    for (unsigned i = 0; i < MAX_LANES; ++i)
    {
        _matrix[i] = new Position*[MAX_LENGTH];
        
        for (unsigned j = 0; j < MAX_LENGTH; ++j)
        {
            _matrix[i][j] = NULL;
        }
    }
}

bool Traffic_Matrix::insert(Position* obj)
{
    // Object already located at the position
    if (_matrix[obj->lane()][obj->distance()])
    {
        return false;
    }

    _matrix[obj->lane()][obj->distance()] = obj;
    return true;
}

void Traffic_Matrix::update(Position* obj)
{
    
    

}

void Traffic_Matrix::display() const
{
    std::cout << "Y = You, C = Car, | = Intersection\n\n ";

    print_border();    

    for (unsigned i = 0; i < MAX_LANES; ++i)
    {
        print_lane(i);
    }

    std::cout << "\n0 Meters";
    for (unsigned i = 0; i < MAX_LENGTH - 8; ++i)
    {
        std::cout << " ";
    }
    std::cout << MAX_LENGTH << " Meters\n";

    return;
}

void Traffic_Matrix::print_lane(const int& lane) const
{
    std::cout << "\n|";
    for (unsigned j = 0; j < MAX_LENGTH; ++j)
    {
        // No object in the lane position
        if (!_matrix[lane][j])
        {
            std::cout << " ";
        }
        else
        {
            std::cout << "C";
        }
    }

    std::cout << "|\n "; // TODO Street name too

    print_border();
    return;
}

void Traffic_Matrix::print_border() const
{
    for (unsigned i = 0; i < MAX_LENGTH / 10; ++i)
    {
        std::cout << "--------->";
    }
    return;
}

