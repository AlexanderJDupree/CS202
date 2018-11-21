package com.balanced_tree;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Iterator;

import static org.junit.jupiter.api.Assertions.*;

class Assert_Tree implements Functor {

    private int counter = 0;
    private Iterator<Entry<Integer, Character>> iter;
    private ArrayList<Entry<Integer, Character>> entries;

    Assert_Tree(ArrayList<Entry<Integer, Character>> entries) {
        this.entries = entries;
        iter = this.entries.iterator();
    }

    @Override
    public void accept(Entry entry) {
        assertEquals(0, entry.compareTo(iter.next()));
    }
}

class B_Tree_Test {

    // Empty Test Fixture
    private B_Tree empty = new B_Tree();

    private B_Tree<Integer, Character> test = new B_Tree<>();

    void build_tree(int [] keys, char [] vals) {
        for (int i = 0; i < keys.length; ++i) {
            test.insert(keys[i], vals[i]);
        }
    }

    ArrayList<Entry<Integer, Character>> build_entries(int [] keys, char [] vals) {

        ArrayList<Entry<Integer, Character>> entries = new ArrayList<>();

        for (int i = 0; i < keys.length; ++i) {
            entries.add(i, new Entry<>(keys[i], vals[i]));
        }

        return entries;
    }

    @BeforeEach
    void setup() {
        test.clear();
    }

    @Test
    void size() {
        assertEquals(0, empty.size());
    }

    @Test
    void empty() {
        assertTrue(empty.empty());
    }

    @Test
    void insert() {

        int [] keys = { 4, 3, 2, 1 };
        char [] vals = { 'a', 'b', 'c', 'd' };

        build_tree(keys, vals);

        assertEquals(4, test.size());
    }

    @Test
    void preorder_traversal() {

        int [] keys = { 40, 30, 20, 10, 0, 50, 60, 5, 70, 45, 48, 49, 75, 80, 65, 49, 49 };
        char [] vals = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's'};
        int [] expected = { 30, 50, 10, 0, 5, 20, 45, 49, 40, 48, 49, 49, 70, 60, 65, 75, 80 };

        build_tree(keys, vals);

        test.preorder_traversal(new Display_All());

        test.preorder_traversal(new Assert_Tree(build_entries(expected, vals)));
    }

    @Test
    void height() {
        int [] keys = { 40, 30, 20, 10, 0, 50, 60, 5, 70, 45, 48, 49, 75, 80, 65, 49, 49 };
        char [] vals = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's'};

        build_tree(keys, vals);

        assertEquals(3, test.height());
    }

    @Test
    void leaves() {
        int [] keys = { 40, 30, 20, 10, 0, 50, 60, 5, 70, 45, 48, 49, 75, 80, 65, 49, 49 };
        char [] vals = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's'};

        build_tree(keys, vals);

        assertEquals(7, test.leaves());
    }

    @Test
    void find() {
        int [] keys = { 40, 30, 20, 10, 0, 50, 60, 5, 70, 45, 48, 49, 75, 80, 65, 49, 49 };
        char [] vals = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's'};

        build_tree(keys, vals);

        assertEquals(0, test.find(49).compareTo('m'));
        assertNull(test.find(101));
    }
}
