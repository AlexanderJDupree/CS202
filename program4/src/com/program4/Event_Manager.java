/*
File: Event_Manager.java

Description: The Event Manager manages a collection of event objects ordered by
             the events point values. The Event Manager is derived from the
             generic B_Tree class and as such is a 2-3-4 tree.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

import com.balanced_tree.B_Tree;
import com.balanced_tree.Entry;
import com.balanced_tree.Functor;


class Display_Events implements Functor {
    @Override
    public void accept (Entry entry) {
       System.out.println(entry.val());
    }
}

public class Event_Manager extends B_Tree<Integer, Event> {

    Event_Manager() {
        super(4); // Event Manager is a 2-3-4 tree
    }

    public void display_events() {
        preorder_traversal(new Display_Events());
    }
}

