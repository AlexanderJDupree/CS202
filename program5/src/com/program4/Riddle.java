/*
File: Riddle.java

Description: Riddle class extends the Event class to allow for a logic based
             event where the player wins points based on their answer to a
             riddle.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

import com.user_interface.Interface;

public class Riddle extends Event {

    private final String answer;

    Riddle() {
        this(0, "N/A", "N/A");
    }

    Riddle(int points, String description, String answer) {
        super(points, description);

        this.answer = answer;
    }

    @Override
    public int action() {
        System.out.println(this.description());

        return (evaluate_guess()) ? this.points() : 0;
    }

    private boolean evaluate_guess() {

        if (answer.compareTo(Interface.get_input()) == 0) {
            System.out.println("\n\tThat is correct!");
            Interface.pause_console();
            return true;
        }

        System.out.println("\nThat is incorrect. The answer was: " + answer);

        return false;
    }
}
