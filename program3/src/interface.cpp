/*
File: interface.cpp

Description: Implementation file for the Interface namespace. 

Author: Alexander DuPree

Class: CS202

Assignment: program 2

Date: 10/28/2018
*/

#include "interface.h"

bool Interface::get_bool(const char* prompt)
{
    std::cout << prompt << " (Y/N): ";
    if (std::tolower(get_input<char>("")) == 'y')
    {
        return 1;
    }
    return 0;
}

char* Interface::get_char_input(char* buffer, int size, const char* prompt)
{
    std::cout << prompt;
    std::cin.getline(buffer, size);

    return buffer;
}

void Interface::display_error(const char* message)
{
    std::cout << message << std::endl;
    return;
}

void Interface::pause_console(const char* prompt)
{
    std::cout << prompt;
    std::cin.get();
    return;
}

bool Interface::repeat_loop(const char* prompt)
{
    std::cout << prompt;
    return std::tolower(get_input<char>("\n> ")) ==  'y';
}

void Interface::clear_screen() 
{
    std::cout << std::string(100, '\n');
    return;
}

void Interface::reset_input_stream()
{
    // reset failed state
    std::cin.clear();

    // discard characters up to the limit of the stream OR to newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}
