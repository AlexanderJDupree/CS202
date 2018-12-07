/*
File: Event.java

Description: The Event object serves as the abstract base class for all events
             in the system. The basic structure of the Event is when the action
             method is called, the user must interact with the event and is then
             awarded points according to their actions. The Event is ordered by
             their point values.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

public abstract class Event implements Comparable<Event> {

    private final int points;
    private final String description;

    Event() {
        this(0, "N/A");
    }

    Event(int points, String description) {
        this.points = points;
        this.description = description;
    }

    @Override
    public int compareTo(Event event) {
        return this.points - event.points;
    }

    @Override
    public String toString() {
        return "Type: " + getClass().getName() + "\nEvent: " + description + "\nPoints: " + points + "\n";
    }

    public final String description() {
        return this.description;
    }

    public final int points() {
        return this.points;
    }

    public abstract int action();
}

