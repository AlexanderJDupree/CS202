/*
File: Chance.java

Description: Chance class extends the Event class to allow for a probality based
             event where the player has a chance of winning points based on their
             decision.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

import com.user_interface.Interface;

import java.util.Random;

public class Chance extends Event {

    private final int max;
    private final int min;

    Chance() {
        this(0, "N/A", 0, 100);
    }

    Chance(int points, String description, int min, int max) {
        super(points, description);
        this.max = max;
        this.min = min;
    }

    @Override
    public int action() {
        System.out.println(this.description());

        return (evaluate_input()) ? this.points() : this.points() / 2;
    }

    private boolean evaluate_input() {

        int input = Interface.get_int("> ", min, max);

        int rand = rand_int();
        if (rand == input) {
            System.out.println("\nCongratulations! You got lucky!");
            Interface.pause_console();
            return true;
        }

        System.out.println("\nSorry, better luck next time! Rolled a " + rand);
        Interface.pause_console();
        return false;
    }

    private int rand_int() {
        Random rand = new Random();
        return rand.nextInt((max + 1) - min) + min;
    }
}
