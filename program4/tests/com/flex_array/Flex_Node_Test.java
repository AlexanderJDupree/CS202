package com.flex_array;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.function.Consumer;

import static org.junit.jupiter.api.Assertions.*;

class assert_node implements Consumer<Integer> {

    int [] expected;
    int index;

    assert_node(int [] expected) {
        this.expected = expected;
        index = 0;
    }

    @Override
    public void accept(Integer num) {
        assertTrue(num.equals(expected[index++]));
    }

}

class Flex_Node_Test {

    Flex_Node<Integer> test = new Flex_Node<>(5);

    void fill_test_node() {
       for(int i = 0; i < 5; ++i) {
           test.add(i);
       }
    }

    @BeforeEach
    void before() {
        test.clear();
    }

    @Test
    void full() {
        fill_test_node();

        assertTrue(test.full());
    }

    @Test
    void empty() {

        assertTrue(test.empty());

        test.add(7);

        assertFalse(test.empty());
    }

    @Test
    void add() {

        for (int i = 0; i < 5; ++i) {
            assertTrue(test.add(i));
        }

        assertFalse(test.add(7));
    }

    @Test
    void for_each() {

        int [] expected = { 0, 1, 2, 3, 4 };

        fill_test_node();

        test.for_each(new assert_node(expected));
    }
}