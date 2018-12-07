/*
File: B_Tree.java

Description: B_Tree.java defines the generic B_Tree class. The B_Tree class can
             use any object reference as its key or value data type. The B_Tree
             class is supposed to be generic and support B_Tree of any even degree.
             Currently the insertion and splitting algorithms only work for trees
             of degree 4. I.E. This Generic B_Tree implementation currently only
             support 2-3-4 trees.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.balanced_tree;

class Display_All implements Functor {
    @Override
    public void accept (Entry entry) {
        System.out.print("(" + entry.key() + ", " + entry.val() + ") ");
    }
}

public class B_Tree<Key extends Comparable<? super Key>, Value>
{
    private B_Node<Key, Value> root;

    private  int size = 0; // Number of elements in the tree

    /**
     * Default B_Tree is a 2-3-4 tree
     */
    public B_Tree() {
        this(4);
    }

    public B_Tree(int degree) {
        root = new B_Node<>(degree, null);
    }

    /****** CAPACITY ******/

    /**
     * @return Number of elements in the collection
     */
    public int size()
    {
        return this.size;
    }

    /**
     * @return True if container has no elements
     */
    public boolean empty()
    {
        return size == 0;
    }

    /****** DIAGNOSTICS ******/

    /**
     * @return the height of the tree, 1 element will return a height of 1
     */
    public int height() {
        return height(root);
    }

    private int height(B_Node<Key, Value> root) {
        if (root.leaf()) {
            return 1;
        }

        return 1 + height(root.children.get(0));
    }

    /**
     * @return number of leaves
     */
    public int leaves() {
        return leaves(root);
    }

    private int leaves(B_Node<Key, Value> root) {
        if(root.leaf()) {
            return 1;
        }

        int total = 0;
        for(B_Node<Key, Value> child : root.children) {
            total += leaves(child);
        }

        return total;
    }

    /****** MODIFIERS ******/

    /**
     * @param key used for ordering and associated Value val
     * @return Self Reference for chaining
     */
    public B_Tree<Key, Value> insert(Key key, Value val) {

        if (root.full()){
            root.split_root();
        }
        insert(root, new Entry<>(key, val));
        return this;
    }

    private void insert(B_Node<Key, Value> root, Entry<Key, Value> entry) {
        // Check if node is full
        if (root.full()) {
            root.split();
            root = root.parent;
        }

        // If node is a leaf, add entry
        if (root.leaf()) {
            root.insert(entry);
            ++size;
            return;
        }

        // Insert with r-call to correct child
        insert(root.find_path(entry), entry);
    }

    /**
     * @return Self Reference for chaining
     */
    public B_Tree<Key, Value> clear() {

        root = new B_Node<>(root.degree(), null);

        size = 0;

        return this;
    }

    /****** OPERATIONS ******/

    /**
     * @param key is the object the comparator will use to determine equality
     * @return Value OR null if no matching key is found
     */
    public Value find(Key key) {
        return find(root, key);
    }

    private Value find(B_Node<Key, Value> root, Key key) {

        Value target = root.find(key);
        if(target != null) {
            return target;
        }

        // No  matching key found
        if (root.leaf()) {
            return null;
        }

        return find(root.find_path(key), key);
    }

    public void display_all() {
        preorder_traversal(new Display_All());
    }

    /****** TRAVERSAL ******/

    /**
     * @param functor implementing object
     * @return number of nodes visited
     */
    public int preorder_traversal(Functor functor) {
        return preorder_traversal(root, functor);
    }

    private int preorder_traversal(B_Node<Key, Value> root, Functor functor) {

        root.for_each(functor);

        int total = 0;
        for (int i = 0; i < root.children.size(); ++i) {
            total += preorder_traversal(root.children.get(i), functor);
        }
        return ++total;
    }

}
