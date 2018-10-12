/*
 
 File: linked_list.cpp

 Brief: Header defines protoypes and internal classes for the linear linked list
        data structure.

 Copyright (c) 2018 Alexander DuPree

 This software is released as open source through the MIT License

 Authors: Alexander DuPree

 https://github.com/AlexanderJDupree/LinkedListsCPP

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

    // Removes each element from the container
    void clear();

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
    @struct: Node

    @brief: Node is the atomic member for the linked list class. It stores
            the desired data and contains a pointer to the next node in the list.
    */
    struct Node
    {
        // Default values are default constrution and NULL
        Node(const_reference value = value_type(), Node* next = NULL) 
            : data(value), next(next) {}

        value_type data;
        Node* next;

    };

    Node* head;
    Node* tail;

    size_type _size; // Keeps track of the number of elements in the list

    /* Recursive Functions */

    void clear_list(Node*& current);

    template <class Predicate>
    int remove_if(Predicate pred, Node*& current, Node* prev=NULL);

    /* Subroutines */

    // Throws a logic error exception if the node* is NULL
    void throw_if_null(Node* node) const;

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
