/*
File: End_Event.java

Description: End Event class will trigger a -1000 point loss for the player,
             bringing the total points to under 0. This will signal to the main
             that the game has ended.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

import com.user_interface.Interface;

public class End_Event extends Event {

    End_Event(int points, String description) {
        super(points, description);
    }

    @Override
    public int action() {
        System.out.println("You've reached an end event, quick whats your favorite color?");
        String color = Interface.get_input("Enter your favorite color: ");
        System.out.println(color + " is my favorite color too! Congratulation you beat the game!");
        return -1000;
    }
}
