package com.balanced_tree;

import java.util.Iterator;
import java.util.function.Consumer;

interface Functor extends Consumer<Entry> {

}

class Display_All implements Functor {
    @Override
    public void accept (Entry entry) {
        System.out.print("(" + entry.key() + ", " + entry.val() + ") ");
    }
}

class B_Tree<Key extends Comparable<? super Key>, Value>
{
    private B_Node<Key, Value> root;

    private  int size = 0; // Number of elements in the tree

    /**
     * Default B_Tree is a 2-3-4 tree
     */
    B_Tree() {
        this(4);
    }

    B_Tree(int degree) {
        root = new B_Node<>(degree);
    }

    /****** CAPACITY ******/

    /**
     * @return Number of elements in the collection
     */
    int size()
    {
        return this.size;
    }

    /**
     * @return True if container has no elements
     */
    boolean empty()
    {
        return size == 0;
    }

    /****** DIAGNOSTICS ******/

    /**
     * @return the height of the tree, 1 element will return a height of 1
     */
    //int height();

    /**
     * @return number of leaves
     */
    //int leaves();

    /****** MODIFIERS ******/

    /**
     * @param key used for ordering and associated Value val
     * @return Self Reference for chaining
     */
    B_Tree<Key, Value> insert(Key key, Value val)
    {
        if (root.full())
        {
            root.split();
        }

        insert(root, new Entry<>(key, val));
        return this;
    }

    private void insert(B_Node<Key, Value> root, Entry<Key, Value> entry)
    {
        // Check if node is full
        if (root.full())
        {
            root.split();
            return;
        }

        // If node is a leaf, add entry
        if (root.leaf())
        {
            root.insert(entry);
            ++size;
            return;
        }

        // Insert with r-call to correct child
        insert(root.children.get(root.find_path(entry)), entry);
    }

    /**
     * @return Self Reference for chaining
     */
    B_Tree<Key, Value> clear() {

        root = new B_Node<>(root.degree());

        size = 0;
        return this;
    }

    /****** OPERATIONS ******/

    /**
     * @param key is the object the comparator will use to determine equality
     * @return T reference to the first object matching equal to the key
     */
    //T find(T key);

    /****** TRAVERSAL ******/

    /**
     *
     * @param functor functor implementing object
     * @return number of nodes visited
     */
    public int preorder_traversal(Functor functor) {
        return preorder_traversal(root, functor);
    }

    private int preorder_traversal(B_Node<Key, Value> root, Functor functor) {
        if (root == null)
        {
            return 0;
        }

        root.for_each(functor);

        int total = 0;
        for (int i = 0; i < root.children.size(); ++i) {
            total += preorder_traversal(root.children.get(i), functor);
        }
        return ++total;
    }
}
