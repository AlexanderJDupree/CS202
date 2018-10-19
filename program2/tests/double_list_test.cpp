/*
 
 File: double_list_test.cpp

 Brief: Unit tests for linear linked list data structure

 Copyright (c) 2018 Alexander DuPree

 This software is released as open source through the MIT License

 Authors: Alexander DuPree, Jacob Bickle

 https://github.com/AlexanderJDupree/LinkedListsCPP

*/

#include <catch.hpp>
#include "double_list.h"

TEST_CASE("Constructing double_linked_list objects", "[double_list], [constructors]")
{
    SECTION("Default construction")
    {
        double_linked_list<int> list;

        REQUIRE(list.empty());
    }
    SECTION("Copy construction")
    {
        int nums[] = {1, 2, 3, 4, 5};

        double_linked_list<int> origin(nums, nums + 5);
        double_linked_list<int> copy(origin);

        REQUIRE(origin == copy);
        REQUIRE(copy.size() == 5);
    }
    SECTION("Range based construction on a populated array")
    {
        int nums[] = {1, 2, 3, 4, 5};


        double_linked_list<int> list(nums, nums + 5);

        double_linked_list<int>::const_iterator it;
        int i = 0;
        for(it = list.begin(); it != list.end(); ++it)
        {
            bool assert = *it == nums[i++];
            REQUIRE(assert);
        }
    }
    SECTION("Range based construction on an empty array")
    {
        int nums[3];

        double_linked_list<int> list(nums, nums + 3);

        double_linked_list<int>::const_iterator it;

        int i = 0;

        for(it = list.begin(); it != list.end(); ++it)
        {
            bool assert = *it == nums[i++];
            REQUIRE(assert);
        }
    }
}

TEST_CASE("Using clear to erase the list", "[double_list], [clear], [destructor]")
{
    SECTION("An empty list")
    {
        double_linked_list<char> list;

        list.clear();

        REQUIRE(list.empty());
    }
    SECTION("A populated list")
    {
        char letters[] = { 'a', 'b', 'c' };

        double_linked_list<char> list(letters, letters + 3);

        list.clear();

        REQUIRE(list.empty());
    }
}

TEST_CASE("Using swap to reassign data", "[double_list], [swap]")
{
    SECTION("An empty list and a populated list")
    {
        int nums[] = { 1, 2, 3 };

        double_linked_list<int> old(nums, nums + 3);

        double_linked_list<int> list;

        double_linked_list<int>::swap(list, old);

        int i = 0;
        double_linked_list<int>::iterator it;
        for (it = list.begin(); it != list.end(); ++it)
        {
            REQUIRE(*it == ++i);
        }
    }
    SECTION("two empty lists")
    {
        double_linked_list<int> old;
        double_linked_list<int> list;

        double_linked_list<int>::swap(list, old);

        bool assert = old == list;
        REQUIRE(assert);
    }
}

TEST_CASE("Using the copy-assignment operator", "[double_list], [operators], [copy-assignment]")
{
    
    SECTION("An empty list and a populated list")
    {
        int nums[] = { 1, 2, 3 };
        double_linked_list<int> old(nums, nums + 3);

        double_linked_list<int> list;

        REQUIRE((list = old) == old);
    }
    SECTION("two empty lists")
    {
        double_linked_list<int> old;
        double_linked_list<int> list;

        REQUIRE((old = list) == list);
    }
}

TEST_CASE("Testing equality between lists", "[double_list], [operators], [equality]")
{
    int nums[] = { 1, 2, 3, 4 };
    SECTION("Two empty lists")
    {
        double_linked_list<int> lhs;
        double_linked_list<int> rhs;

        REQUIRE(lhs == rhs);
    }
    SECTION("Two populated lists of differing sizes")
    {
         double_linked_list<int> lhs(nums, nums + 3);
         double_linked_list<int> rhs(nums, nums + 4);

         REQUIRE(lhs != rhs);
    }
    SECTION("Two populated lists of matching sizes")
    {
         double_linked_list<int> lhs(nums, nums + 3);
         double_linked_list<int> rhs(nums, nums + 2);

         REQUIRE(lhs != (rhs.push_back(4)));
    }
}

TEST_CASE("Popping the front element off the list", "[double_list], [operations], [pop_front]")
{
    SECTION("pop the front of an empty list")
    {
        double_linked_list<int> empty_list;

        REQUIRE(empty_list.pop_front().empty());
    }
    
    SECTION("Pop the front of a list with one element")
    {
        double_linked_list<int> list;

        REQUIRE(list.push_front(1).pop_front().empty());
    }
    
    SECTION("Pop the front of a populated list")
    {
        int nums[] = { 7, 1, 2, 3 };
        double_linked_list<int> list(nums, nums + 4);

        list.pop_front();

        int i = 0;
        double_linked_list<int>::iterator it;
        for (it = list.begin(); it != list.end(); ++it)
        {
            REQUIRE(*it == ++i);
        }
    }
    SECTION("Pop the front of an empty list with out parameter")
    {
        int i = 7;

        double_linked_list<int> empty_list;

        REQUIRE(empty_list.pop_front(i) == 7);
    }
    SECTION("Pop the front of a populated list")
    {
        int i = 7;
        int nums[] = { 1, 2, 3, 4 };

        double_linked_list<int> list(nums, nums + 4);

        REQUIRE(list.pop_front(i) == 1);
    }
}


// TODO Ensure the list is still linked in reverse
TEST_CASE("Removing a specific element from a list", "[double_list], [operations], [remove]")
{
    int nums[] = { 1, 4, 2, 3, 4 };
    double_linked_list<int> list(nums, nums + 5);

    SECTION("Remove from a populated list")
    {
        REQUIRE(list.remove(4) == 2);
        REQUIRE(list.size() == 3);

        int i = 4;
        double_linked_list<int>::iterator it;
        for (it = list.rbegin(); it != list.rend(); --it)
        {
            REQUIRE(*it == --i);
        }
    }

    SECTION("Removing an item not found in a list")
    {
        REQUIRE(list.remove(7) == 0);
    }
}


struct remove_seven
{
    bool operator() (const int& value)
    {
        return value == 7;
    }
};

TEST_CASE("Using functors to remove a specific element", "[double_list], [operations], [remove_if]")
{
    SECTION("remove_if with a value constructed functor")
    {
        remove_seven functor;

        int nums[] = { 7, 1, 2, 3, 4, 7, 5, 6, 7};

        double_linked_list<int> list(nums, nums + 9);

        REQUIRE(list.remove_if(functor) == 3);

        int i = 0;
        double_linked_list<int>::const_iterator it;
        for (it = list.begin(); it != list.end(); ++it)
        {
            REQUIRE(*it == ++i);
        }
    }
    SECTION("remove_if with the element as the head")
    {
        int nums[] = { 7, 1, 2, 3, 4, 5, 6 };

        double_linked_list<int> list(nums, nums + 7);

        REQUIRE(list.remove_if(remove_seven()));

        int i = 0;
        double_linked_list<int>::const_iterator it;
        for (it = list.begin(); it != list.end(); ++it)
        {
            REQUIRE(*it == ++i);
        }
    }
    SECTION("remove_if with the element as the tail")
    {
        int nums[] = { 1, 2, 3, 4, 5, 6, 7 };

        double_linked_list<int> list(nums, nums + 7);

        REQUIRE(list.remove_if(remove_seven()));

        int i = 0;
        double_linked_list<int>::const_iterator it;
        for (it = list.begin(); it != list.end(); ++it)
        {
            REQUIRE(*it == ++i);
        }
    }
    SECTION("remove_if with no matching element")
    {
        int nums[] = { 1, 2, 3, 4, 5, 6 };

        double_linked_list<int> list(nums, nums + 6);

        REQUIRE(!list.remove_if(remove_seven()));
    }
    SECTION("remove_if with an empty list")
    {
        double_linked_list<int> list;

        REQUIRE_FALSE(list.remove_if(remove_seven()));
    }
    SECTION("remove_if with a single element")
    {
        double_linked_list<int> list;

        REQUIRE(list.push_front(7).remove_if(remove_seven()) == 1);
        REQUIRE(list.empty());
    }
}

TEST_CASE("Using mutable iterators to modify data", "[double_list], [iterators]")
{
    int nums[] = { 1, 2, 3, 4, 5, 6, 7 };

    double_linked_list<int> list(nums, nums + 7);

    int i = 1;
    for (double_linked_list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        ++(*it);
        bool assert = *it = ++i;
        REQUIRE(assert);
    }
}

TEST_CASE("Inserting data with iterators", "[double_list], [modifiers], [insert]")
{
    int nums [] = { 1, 2, 4 };
    double_linked_list<int> list(nums, nums + 3);

    double_linked_list<int> empty;

    SECTION("Inserting data into in empty list")
    {
        REQUIRE(*(empty.insert(1, empty.begin()).begin()) == 1);
    }
    SECTION("Inserting data into the middle of a populated list")
    {
        double_linked_list<int>::iterator it = list.begin();

        ++(++it);

        REQUIRE(list.insert(3, it).size() == 4);

        int i = 0;
        for (it = list.begin(); it != list.end(); ++it)
        {
            REQUIRE(*it == ++i);
        }
    }
}

