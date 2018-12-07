/*
File: Player_History.java

Description: The Player_History class is derived as a Flex_array object and thus contains
             the same functionality as the flex array. The responsibility of the
             Player_History class it to manage the score of the player and the history of
             each event completed throughout the game.

Author: Alexander DuPree

Assignment: Program 5

Date: 24 November 2018
 */

package com.program4;

import com.flex_array.Flex_Array;

public class Player_History extends Flex_Array<Event> {

    private int total_points = 0;

    public boolean add(final Event data, int points) {

        total_points += points;

        return super.add(data);
    }

    public int points() {
        return total_points;
    }

    @Override
    public void clear() {
        total_points = 0;
        super.clear();
    }

}
