/*
File: linked_list.h

Description: linear_linked_list is a data structure that stores data onto a node
             as well as the address for the next element in the container.

             This implementation for the linear linked list is a fully templated
             class. This allows the linear_linked_list to be instantiated to 
             store any data types. 

             To access data or traverse the list, this linear linked list makes 
             use of forward iterators. The forward iterator cannot be decremented.
             The end iterator represents the element one-past the end of the
             list which is a null pointer. dereferencing end iterators causes 
             undifined behavior.


Author: Alexander DuPree

Class: CS202

Assignment: program 1

Date: 09/28/2018
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef> // NULL
#include <algorithm> // std::swap
#include <stdexcept> // std::logic_error

template <typename T>
class linear_linked_list
{
  public:

    // forward declaration
    class const_forward_iterator;
    class forward_iterator;

    /* Type definitions */
    typedef T                      value_type;
    typedef T*                     pointer;
    typedef T&                     reference;
    typedef const T&               const_reference;
    typedef const T*               const_pointer;
    typedef size_t                 size_type;
    typedef forward_iterator       iterator;
    typedef const_forward_iterator const_iterator;
    typedef linear_linked_list<T>  self_type;

    /****** CONSTRUCTORS ******/

    // Default
    linear_linked_list();

    // Ranged based
    template <class InputIterator>
    linear_linked_list(InputIterator begin, InputIterator end);

    // Copy Constructor
    linear_linked_list(const self_type& origin);
   
    // Destructor
    ~linear_linked_list();
     
    /****** MODIFIERS ******/

    // Adds an element to the front of the list
    self_type& push_front(const_reference data);

    // Adds an element to the back of the list
    self_type& push_back(const_reference data);

    // Removes the element at the front of the list
    self_type& pop_front();

    // Copies the front element onto the out_param and removes it
    reference pop_front(reference out_param);

    // Copies the data onto a node before the insert_point
    self_type& insert(const_reference data, iterator insert_point);

    // Removes each element from the container
    void clear();

    // Removes the element corresponding with the iterator from the list
    int remove(iterator target);

    // Removes the all items fullfilling the predicate functor
    template <class Predicate>
    int remove_if(Predicate pred);

    /****** CAPACITY ******/

    // returns true if the list is empty
    bool empty() const;

    // returns the number of elements in the list
    size_type size() const;

    /****** ELEMENT ACCESS ******/

    // Returns a direct reference to the front element, throws if list is empty
    reference front();
    const_reference front() const;

    // Returns a direct reference to the rear element, throws if list is empty
    reference back();
    const_reference back() const;

    /****** ITERATORS ******/

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    /****** COMPARISON OPERATORS ******/

    // Compares sizes, then comapres each element of the list for equality
    bool operator==(const self_type& rhs) const;

    // returns the logical NOT of the equality comparison
    bool operator!=(const self_type& rhs) const;

    /****** COPY-ASSIGNMENT AND SWAP ******/

    // creates a copy of the origin, then swaps ownership with the copy
    self_type& operator=(self_type copy);

    // Swaps pointers to each other's resources. effectively reassigning 
    // ownership.
    static void swap(self_type& new_list, self_type& old_list);

  private:
    
    /* 
    @class: Node

    @brief: Node is the atomic member for the linked list class. It stores
            the desired data and contains a pointer to the next node in the list.
    */
    class Node
    {
      public:

        // Default values are default constrution and NULL
        Node(const_reference value = value_type(), Node* next = NULL);

        Node*& next();
        reference data();

      private:

        value_type _data;
        Node* _next;

    };

    Node* head;
    Node* tail;

    size_type _size; // Tracks the number of elements in the list

    /* Recursive Functions */

    void clear_list(Node*& current);

    template <class Predicate>
    int remove_if(Predicate pred, Node*& current, Node* prev=NULL);

    void insert(const_reference data, Node*& current, Node* target);

    /* Subroutines */

    // Throws a logic error exception if the node* is NULL
    void throw_if_null(Node* node) const;

    /* Functors */
    struct remove_functor
    {
        remove_functor(const_reference target) : _target(target) {}
        
        bool operator()(const_reference data)
        {
            return _target == data;
        }

        value_type _target;
    };

    public:

    /*
    @class: const_forward_iterator
    
    @brief: The const_forward_iterator is a read-only abstraction of the node 
            pointer. The const_forward_iterator provides methods for inspecting
            data, and incrementation. This iterator type does not support 
            decrementation or random access

            Because the iterator does not manage any resources and it's only 
            member is a pointer, we allow the use of the DEFAULT destructor, 
            copy constructor, and copy-assignment operator.
    */
    class const_forward_iterator
    {
      public:

        typedef const_forward_iterator  self_type;

        /* Constructors */

        // default constructor points the iterator to NULL
        const_forward_iterator(Node* ptr = NULL) : node(ptr) {}

        /* Operator Overloads */

        self_type& operator++(); // Prefix ++
        self_type operator++(int); // Postfix ++

        const_reference operator*() const;
        const_pointer operator->() const;

        bool null() const;

        // Iterators are equal if they point to the same memory address
        bool operator==(const self_type& rhs) const;
        bool operator!=(const self_type& rhs) const;
      
      protected:

        void throw_if_null(Node* node, const char* err) const;

        Node* node;

    };

    /*
    @class: forward_iterator
    
    @brief: The forward_iterator is a read/write abstraction of the node 
            pointer. The forward_iterator inherits all methods from the 
            const_forward_iterator but overrides the reference operators
            to allow the client to mutate data
    */
    class forward_iterator : public const_forward_iterator
    {
      public:

        /* Type definitions */
        typedef forward_iterator    self_type;

        forward_iterator(Node* ptr = NULL) : const_forward_iterator(ptr) {}

        reference operator*();

        pointer operator->();

    };
};

#include "linked_list.cpp"

#endif //LINKED_LIST_H

