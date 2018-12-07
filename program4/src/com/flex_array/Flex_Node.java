/*
File: Flex_Array.java

Description:  The flex node is a generic linear linked node that contains an array
              as the data member. The size of the array is determined by the Flex
              Arrays ARRAY_SIZE member.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.flex_array;

import java.util.function.Consumer;

final class Flex_Node<E> {

    private E [] data;
    private int size;
    private Flex_Node<E> next;

    Flex_Node() {
        this(5, null);
    }

    Flex_Node(int array_size) {
        this(array_size, null);
    }

    // Suppress unchecked warning for generic array creation
    @SuppressWarnings("unchecked")
    Flex_Node(int array_size, Flex_Node<E> next)  {
        size = 0;
        this.next = next;
        data = (E[]) new Object[array_size];
    }

    public boolean full() {
        return size >= data.length;
    }

    public boolean empty() {
        return size == 0;
    }

    public boolean add(final E data) {

        // TODO Should a nullptr exception be thrown if data == null??

        if (full()) {
            return false;
        }

        this.data[size++] = data;
        return true;
    }

    public void for_each(Consumer<? super E> action) {
        for_each(action, 0);
    }

    private void for_each(Consumer<? super E> action, int index) {
        if(index >= size || index < 0) {
            return;
        }

        action.accept(data[index]);

        for_each(action, ++index);
    }

    public Flex_Node<E> next() {
        return this.next;
    }

    public Flex_Node<E> next(Flex_Node<E> next) {
        this.next = next;
        return this.next;
    }

    @SuppressWarnings("unchecked")
    public void clear() {
        size = 0;
        data = (E[]) new Object[data.length];
    }

}
