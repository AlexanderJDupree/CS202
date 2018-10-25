/*
File: interface.h

Description: 

Author: Alexander DuPree

Class: CS163

Assignment: program 4

Date: 08/03/2018
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <limits> // numeric_limits
#include <iostream> // cout, cin

namespace Interface
{
    // Takes in an out parameter and OVERRIDES it with user input
    template <typename T>
    T& get_input(T& out_param, const char* prompt = "\n> ");

    // Returns input BY VALUE, this method should only be used on primitive types.
    template <typename T>
    T get_input(const char* prompt = "\n> ");

    char* get_char_input(char* buffer, int size, const char* prompt = "\n> ");

    // Prints a prompt, waits for input
    void pause_console(const char* prompt = "\nPress ENTER to continue\n");

    // Basic prompt and evaluation for use in loops
    bool repeat_loop(const char* prompt = "\nAgain? Y/N: ");

    // Prints 100 newlines to the screen to give the illusion of a cleared 
    // screen
    void clear_screen();

    // Prints message to the console
    void display_error(const char* message);

    // Clears fail flags, flushes input buffer
    void reset_input_stream();
};

template <typename T>
T& Interface::get_input(T& out_param, const char* prompt)
{
    std::cout << prompt;
    std::cin >> out_param;

    reset_input_stream();

    return out_param;
}

template <typename T>
T Interface::get_input(const char* prompt)
{
    T input;

    std::cout << prompt;
    std::cin >> input;

    reset_input_stream();

    return input;
}

#endif // INTERFACE_H
