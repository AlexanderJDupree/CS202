/*
File: Decision.java

Description: Decision class extends the Event class to allow for a decision based
             event where the player wins points based on their decision.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

import com.user_interface.Interface;

public class Decision extends Event {

    private final String choice_one;
    private final String choice_two;

    Decision() {
        this(0, "N/A", "N/A", "N/A");
    }

    Decision(int points, String description, String choice1, String choice2) {
        super(points, description);

        this.choice_one = choice1;
        this.choice_two = choice2;
    }

    @Override
    public int action() {

        System.out.println(this.description());

        System.out.println("Your choices are: ");
        System.out.println("\n1. " + choice_one + "  2. " + choice_two);

        return (evaluate_input()) ? this.points() : this.points() / 2;
    }

    private boolean evaluate_input() {
        if(Interface.get_input().equalsIgnoreCase("1")){
            System.out.println("\nThat was the correct decision!");
            Interface.pause_console();
            return true;
        }
        System.out.println("\nThat was the wrong decision!");
        Interface.pause_console();
        return false;
    }

}
