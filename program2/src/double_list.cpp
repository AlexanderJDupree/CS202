/*
File: double_list.h

Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef DOUBLE_LIST_CPP
#define DOUBLE_LIST_CPP

#include "double_list.h"

/****** CONSTRUCTORS ******/

// default constructor
template <typename T>
double_linked_list<T>::double_linked_list() 
    : head(NULL), tail(NULL), _size(0) {}

// ranged based constructor
template <typename T>
template <class InputIterator>
double_linked_list<T>::double_linked_list(InputIterator begin, InputIterator end) 
    : head(NULL), tail(NULL), _size(0)
{
    for(; begin != end; ++begin)
    {
        push_back(*begin);
    }
}

// Copy constructor
template <typename T>
double_linked_list<T>::double_linked_list(const self_type& origin) 
    : head(NULL), tail(NULL), _size(0)
{
    // TODO refactor to exclude iterators
    const_iterator it;
    for (it = origin.begin(); it != origin.end(); ++it)
    {
        push_back(*it);
    }
}

// Destructor
template <typename T>
double_linked_list<T>::~double_linked_list()
{
    clear();
}

/****** MODIFIERS ******/

template <typename T>
double_linked_list<T>& double_linked_list<T>::push_front(const_reference data)
{
    Node* temp = new Node(data, head);
    head = temp;

    // Edge case : List was empty
    if (tail == NULL)
    {
        tail = head;
    }

    ++_size;
    return *this;
}

template <typename T>
double_linked_list<T>& double_linked_list<T>::push_back(const_reference data)
{
    if(empty())
    {
        return push_front(data);
    }

    Node* temp = new Node(data, NULL, tail);

    tail->next() = temp;
    tail = temp;

    ++_size;
    return *this;
}

template <typename T>
double_linked_list<T>& double_linked_list<T>::pop_front()
{
    if (empty())
    {
        return *this;
    }

    Node* temp = head->next();

    // Edge case, there is only one element in the list
    if (tail == head)
    {
        tail = temp;
    }
    else
    {
        temp->prev() = NULL;
    }

    delete head;

    head = temp;

    --_size;

    return *this;
}

template <typename T>
T& double_linked_list<T>::pop_front(reference out_param)
{
    if(!empty())
    {
        out_param = head->data();

        pop_front();
    }
        
    return out_param;
}

template <typename T>
double_linked_list<T>& double_linked_list<T>::insert(const T& data, iterator insert_point)
{
    if (head == insert_point.node)
    {
        push_front(data);
    }
    else
    {
        Node* temp = new Node(data, insert_point.node, insert_point.node->prev());
        insert_point.node->prev() = temp;
        temp->prev()->next() = temp;
        ++_size;
    }
    return *this;
}

template <typename T>
void double_linked_list<T>::clear()
{
    if(empty())
    {
        return;
    }

    // clear_list is a recursive function that deletes each node of the list
    clear_list(head);

    _size = 0;

   tail = NULL;

    return;
}

template <typename T>
void double_linked_list<T>::clear_list(Node*& current)
{
    // While the current node pointer is not at the end of the list
    if (current != tail)
    {
        // Recursive call to travel to the end of the list
        clear_list(current->next());
    }

    // Deletes the current node as the stack unwinds
    delete current;
    current = NULL;

    return;
}

template <typename T>
template <class Predicate>
int double_linked_list<T>::remove_if(Predicate pred)
{
    if (empty())
    {
        return 0;
    }
    
    return remove_if(pred, head);
}

template <typename T>
int double_linked_list<T>::remove(iterator target)
{
    return remove_if(remove_functor(*target), head);
}

template <typename T>
int double_linked_list<T>::remove(const_reference target)
{
    return remove_if(remove_functor(target), head);
}

template <typename T>
template <class Predicate>
int double_linked_list<T>::remove_if(Predicate pred, Node*& current)
{
    // Base Case: Traversed the whole list
    if(current == NULL)
    {
        return 0;
    }

    // Predicate fulfilled, remove this element
    if(pred(current->data()))
    {
        if (tail == current)
        {
            tail = tail->prev();
        }

        Node* temp = current;

        current = current->next();

        if (current)
        {
            current->prev() = temp->prev();
        }

        delete temp;

        --_size;

        return 1 + remove_if(pred, current);
    }

    return remove_if(pred, current->next());
}

/****** CAPACITY ******/

template <typename T>
bool double_linked_list<T>::empty() const
{
    return !(head);
}

template <typename T>
typename double_linked_list<T>::size_type double_linked_list<T>::size() const
{
    return _size;
}

/****** ELEMENT ACCESS ******/

template <typename T>
T& double_linked_list<T>::front() 
{
    throw_if_null(head);

    return head->data();
}

template <typename T>
const T& double_linked_list<T>::front() const
{
    throw_if_null(head);

    return head->data();
}

template <typename T>
T& double_linked_list<T>::back() 
{
    throw_if_null(tail);

    return tail->data();
}

template <typename T>
const T& double_linked_list<T>::back() const
{
    throw_if_null(tail);

    return tail->data();
}

/****** ITERATORS ******/

template <typename T>
typename double_linked_list<T>::iterator
double_linked_list<T>::begin()
{
    return iterator(head);
}

template <typename T>
typename double_linked_list<T>::const_iterator 
double_linked_list<T>::begin() const
{
    return const_iterator(head);
}

template <typename T>
typename double_linked_list<T>::iterator
double_linked_list<T>::end()
{
    return iterator(NULL);
}

template <typename T>
typename double_linked_list<T>::const_iterator 
double_linked_list<T>::end() const
{
    return const_iterator(NULL);
}

/****** COMPARISON OPERATORS ******/

template <typename T>
bool double_linked_list<T>::operator==(const self_type& rhs) const
{
    // Compare sizes first
    if (rhs.size() != size())
    {
        return false;
    }

    const_iterator left = begin();
    const_iterator right = rhs.begin();

    while(left != end() && right != rhs.end())
    {
        // If any element does not match then return false
        if (*(left++) != *(right++))
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool double_linked_list<T>::operator!=(const self_type& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
typename double_linked_list<T>::self_type& 
// Pass by value is utilized to make use of the copy constructor
double_linked_list<T>::operator=(self_type copy)
{
    // Swap ownership of resources with the copy
    swap(*this, copy);

    // As the copy goes out of scope it destructs with the old data
    return *this;
}

template <typename T>
void double_linked_list<T>::swap(self_type& new_list, self_type& old_list)
{
    using std::swap;

    // Swaps pointers, reassigns ownership
    swap(new_list.head, old_list.head);
    swap(new_list.tail, old_list.tail);
    swap(new_list._size, old_list._size);
    return;
}

template <typename T>
void double_linked_list<T>::throw_if_null(Node* node) const
{
    if(node)
    {
        return;
    }

    throw std::logic_error("Element access fail, NULL pointer");
}

/*******************************************************************************
NODE CLASS
*******************************************************************************/

template <typename T>
double_linked_list<T>::Node::Node(const_reference value, Node* next, Node* prev)
    : _data(value), _next(next), _prev(prev) {}

template <typename T>
typename double_linked_list<T>::Node*&
double_linked_list<T>::Node::next()
{
    return _next;
}

template <typename T>
typename double_linked_list<T>::Node*&
double_linked_list<T>::Node::prev()
{
    return _prev;
}

template <typename T>
T& double_linked_list<T>::Node::data()
{
    return _data;
}

/*******************************************************************************
ITERATOR CLASS
*******************************************************************************/

/* Operator Overloads */
template <typename T>
typename double_linked_list<T>::const_iterator& 
double_linked_list<T>::const_iterator::operator++()
{
    throw_if_null(node, "Unable to increment null iterator");

    // reassign node member to point to the next element in the container
    node = node->next();
    return *this;
}

template <typename T>
typename double_linked_list<T>::const_iterator
double_linked_list<T>::const_iterator::operator++(int)
{
    // Create a copy to satisfy postfix incrementation requirements
    self_type copy = self_type(*this);
    ++(*this);
    return copy;
}

template <typename T>
bool double_linked_list<T>::const_iterator::null() const
{
    return !node;
}

template <typename T>
bool double_linked_list<T>::const_iterator::operator==(const self_type& rhs) const
{
    // Iterators are equal if they point to the same memory address
    return node == rhs.node;
}

template <typename T>
bool double_linked_list<T>::const_iterator::operator!=(const self_type& rhs) const
{
    // return the logical NOT of the equality comparison
    return !(*this == rhs);
}

template <typename T>
typename double_linked_list<T>::const_reference 
double_linked_list<T>::const_iterator::operator*() const
{
    throw_if_null(node, "Error: dereferenced null iterator");
    return node->data();
}

template <typename T>
typename double_linked_list<T>::const_pointer
double_linked_list<T>::const_iterator::operator->() const
{
    throw_if_null(node, "Error: dereferenced null iterator");
    return &node->data();
}

template <typename T>
typename double_linked_list<T>::reference
double_linked_list<T>::iterator::operator*() 
{
    throw_if_null(this->node, "Error: dereferenced null iterator");
    return this->node->data();
}

template <typename T>
typename double_linked_list<T>::pointer
double_linked_list<T>::iterator::operator->()
{
    throw_if_null(this->node, "Error: dereferenced null iterator");
    return &this->node->data();
}

template <typename T>
void double_linked_list<T>::const_iterator::throw_if_null(Node* node, const char* err) const
{
    if (!node)
    {
        throw std::logic_error(err);
    }

    return;
}

#endif // DOUBLE_LIST_CPP
