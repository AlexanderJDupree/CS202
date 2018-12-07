/*
File: Entry.java

Description: Entry object is a generic immutable structure that packages a key
             and value objects together. The Entry object is to be used in table
             type data structures.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.balanced_tree;

public class Entry<Key extends Comparable<? super Key>, Value> implements Comparable<Entry<Key, Value>>
{
    private final Key key;
    private final Value val;

    Entry(Key key, Value val)
    {
        this.key = key;
        this.val = val;
    }

    public final Key key() {
        return this.key;
    }

    public final Value val() {
        return this.val;
    }

    @Override
    public int compareTo(Entry<Key, Value> entry) {
        return key.compareTo(entry.key());
    }
}
