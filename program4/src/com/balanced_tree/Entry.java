package com.balanced_tree;

class Entry<Key extends Comparable<? super Key>, Value> implements Comparable<Entry<Key, Value>>
{
    private final Key key;
    private final Value val;

    Entry(Key key, Value val)
    {
        this.key = key;
        this.val = val;
    }

    final Key key() {
        return this.key;
    }

    final Value val() {
        return this.val;
    }

    @Override
    public int compareTo(Entry<Key, Value> entry) {
        return key.compareTo(entry.key());
    }
}
