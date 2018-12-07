/*
File: Flex_Array.java

Description: The Flex_Array (Flexible Array) data structure is a linked list of arrays.
             The Flex_Array operates similar to other containers and defines methods that
             standard to collection objects

Author: Alexander DuPree

Assignment: Program 5

Date: 24 November 2018
 */

package com.flex_array;

import java.util.function.Consumer;

class Display_All<E> implements Consumer<E>{

    @Override
    public void accept(E obj) {
        System.out.println(obj);
    }
}

public class Flex_Array<E extends Comparable<?super E>> {

    private final int ARRAY_SIZE;

    private int size;

    private Flex_Node<E> head;

    private Flex_Node<E> tail;


    public Flex_Array() {
        this(5);
    }

    public Flex_Array(int array_size) {
        ARRAY_SIZE = array_size;
        size = 0;
        head = new Flex_Node<>(ARRAY_SIZE);
        tail = head;
    }

    public int size() {
        return this.size;
    }

    public boolean empty() {
        return size == 0;
    }

    public boolean add(final E data) {

        ++size;

        // The node successfully accepted the data
        if (tail.add(data)) {
            return true;
        }

        // Node was full, requires a new node
        tail = tail.next(new Flex_Node<>(ARRAY_SIZE));

        return tail.add(data);
    }

    public void for_each(Consumer<? super E> action) {
        for_each(action, head);
    }
    private void for_each(Consumer<? super E> action, Flex_Node<E> current) {
        if(current == null) {
            return;
        }

        current.for_each(action);

        for_each(action, current.next());
    }

    public void display_all() {
        for_each(new Display_All<>());
    }

    public E remove(int index) {
        return null;
    }

    public void clear() {
        size = 0;
        head = new Flex_Node<>(ARRAY_SIZE);
        tail = head;
    }
}
