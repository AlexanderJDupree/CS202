package com.balanced_tree;

import java.util.ArrayList;
import java.util.Collections;

final class B_Node<Key extends Comparable<? super Key>, Value>
{
    private int degree;
    private ArrayList<Entry<Key, Value>> data;

    ArrayList<B_Node<Key, Value>> children;

    B_Node<Key, Value> parent;

    B_Node(int degree, B_Node<Key, Value> parent)
    {
        this.degree = degree;
        data = new ArrayList<>(degree - 1);
        children = new ArrayList<>(degree);
        this.parent = parent;
    }

    private void adopt_child(B_Node<Key, Value> child) {
        child.parent = this;
        children.add(child);
    }

    int degree() {
        return degree;
    }

    boolean full() {
        return data.size() == degree - 1;
    }

    boolean empty() {
        return data.isEmpty();
    }

    boolean leaf() {
        return children.isEmpty();
    }

    Value find(Key key) {
        for (Entry<Key, Value> entry : data) {
            if (entry.key().compareTo(key) == 0) {
                return entry.val();
            }
        }
        return null;
    }

    B_Node<Key, Value> find_path(Entry<Key, Value> entry) {
        return children.get(find_index(entry));
    }

    B_Node<Key, Value> find_path(Key key) {
        return children.get(find_index(key));
    }

    private int find_index(Key key) {

        int index = 0;
        for(; index < data.size(); ++index)
        {
            if(key.compareTo(data.get(index).key()) < 0) {
                return index;
            }
        }
        return index;
    }

    private int find_index(Entry<Key, Value> entry) {

        int index = 0;
        for(; index < data.size(); ++index)
        {
            if (entry.compareTo(data.get(index)) < 0) {
                return index;
            }
        }
        return index;
    }

    void for_each(Functor functor) {
        data.forEach(functor);
    }

    void insert(Entry<Key, Value> entry) {
        if (!full()) {
            data.add(entry);
            Collections.sort(data);
        }
    }

    // Precondition NODE IS FULL
    B_Node split() {

        if (this.data.get(degree - 2).compareTo(parent.data.get(0)) < 0) {
            left_split();
        }
        else {
            right_split();
        }
        return this;
    }

    private void left_split() {
        // Push up the middle
        parent.data.add(0, (this.data.remove((degree / 2) - 1)));

        // Split the node
        B_Node<Key, Value> sibling = new B_Node<>(degree, parent);

        // Adopt right children
        if (!this.leaf()) {
            for (int i = degree / 2; i < degree; ++i) {
                sibling.adopt_child(this.children.remove(degree / 2));
            }
        }
        sibling.data.add(this.data.remove(1));

        // Push sibling to the parent
        parent.children.add(1, sibling);
    }

    private void right_split() {
        // Push up the middle
        parent.data.add(this.data.remove((degree / 2) -1));

        // Split the node
        B_Node<Key, Value> sibling = new B_Node<>(degree, parent);

        // Adopt left children
        if(!this.leaf()) {
            for(int i = 0; i < degree / 2; ++i) {
                sibling.adopt_child(this.children.remove(0));
            }
        }

        sibling.data.add(this.data.remove(0));

        // Push sibling to the parent
        parent.children.add(parent.children.size() - 1, sibling);
    }

    void split_root() {

        // right node takes all values greater than middle
        B_Node<Key, Value> right_node = new B_Node<>(degree, this);
        for (int i = degree / 2; i < degree - 1; ++i) {
            right_node.insert(data.remove(degree / 2));
        }

        // left node takes the remaining values except middle
        B_Node<Key, Value> left_node = new B_Node<>(degree, this);
        for (int i = 0; i < data.size() - 1; ++i) {
            left_node.insert(data.remove(0));
        }

        // Adopt children
        if (!this.leaf()) {
            int i = 0;
            for (B_Node<Key, Value> child : children) {
                if (i++ < children.size() / 2) {
                    left_node.adopt_child(child);
                }
                else {
                    right_node.adopt_child(child);
                }
            }
            children.clear();
        }

        this.children.add(left_node);
        this.children.add(right_node);
    }
}

class NodeMaxCapacity extends Exception {

    NodeMaxCapacity() {
        this("Insert failed because the node is at max capacity");
    }

    private NodeMaxCapacity(String err) {
        super(err);
    }
}
