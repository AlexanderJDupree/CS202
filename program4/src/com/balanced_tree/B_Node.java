package com.balanced_tree;

import java.util.ArrayList;
import java.util.Collections;

final class B_Node<Key extends Comparable<? super Key>, Value>
{
    private int degree;
    private ArrayList<Entry<Key, Value>> data;

    ArrayList<B_Node<Key, Value>> children;

    //Entry<Key, Value> [] data;
    //B_Node [] children;

    B_Node(int degree)
    {
        this.degree = degree;
        data = new ArrayList<>(degree - 1);
        children = new ArrayList<>(degree);
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

    int find_path(Entry<Key, Value> entry) {

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

    void fml() {
        for (Entry<Key, Value> it : data)
        {
            if (it != null){
                System.out.print(it.key() + " ");
            }
            else
            {
                System.out.print("null ");
            }
        }
        System.out.println();
    }


    // TODO Make method exception safe
    void insert(Entry<Key, Value> entry) {
        if (!full()) {
            data.add(entry);
            Collections.sort(data);
        }
    }

    B_Node split() {

        // No children
        B_Node<Key, Value> left_node = new B_Node<>(degree);
        for (int i = 0; i < (degree / 2) - 1; ++i) {
            left_node.insert(data.get(i));
        }
        this.children.add(left_node);

        B_Node<Key, Value> right_node = new B_Node<>(degree);
        for (int i = degree / 2; i < degree - 1; ++i) {
            right_node.insert(data.get(i));
        }
        this.children.add(right_node);

        Entry<Key, Value> temp = data.get((degree/2) - 1);
        data.clear();
        data.add(temp);

        return this;
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
