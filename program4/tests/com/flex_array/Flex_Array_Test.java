package com.flex_array;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Flex_Array_Test {

    Flex_Array<Integer> test = new Flex_Array<>();

    void fill_array(int n) {

        if (n <= 0) {
            return;
        }

        for (int i = 0; i < n; ++i) {
            assertTrue(test.add(i));
        }
    }

    @BeforeEach
    void setUp() {
        test.clear();
    }

    @Test
    void size() {
    }

    @Test
    void empty() {
        assertTrue(test.empty());

        test.add(7);

        assertFalse(test.empty());
    }

    @Test
    void add() {

        fill_array(16);

        assertEquals(16, test.size());
    }

    @Test
    void for_each() {
        int [] expected = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        fill_array(11);

        test.display_all();

        test.for_each(new assert_node(expected));
    }

    @Test
    void remove() {
    }
}