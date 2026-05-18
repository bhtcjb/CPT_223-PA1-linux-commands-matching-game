// Blake Turman

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <new>

#include "Node.hpp"

// template linked list class
template <typename T>
class LinkedList {
    public:
        // construction instantiate head to nullptr and size to 0
        LinkedList() : head(nullptr), size(0) {}

        // destroys and deallocates entire list
        ~LinkedList();

        // returns true if list is empty
        bool isEmpty() const { return head == nullptr && size == 0; }

        // returns number of elements in list
        const size_t& getSize() const { return size; }

        // returns data from head node
        // throws exception if list is empty
        const T& peek() const;

        // overload: returns data from node at input index
        //           returns data from last node if given index is out of list range
        // throws exception if list is empty
        const T& peek(const size_t& index) const;

        // inserts new node with input data to front of list, returns true if success
        // postcond: list is one node larger, head pointer changed
        bool insert(const T& data);

        // overload: inserts new node with input data at input index, returns true if success
        //           inserts node at end of list if given index is out of list range
        // postcond: list is one node larger, head pointer may change
        bool insert(const T& data, const size_t& index);

        // removes node from front of list, returns data from removed node
        // throws exception if list is empty
        // postcond: one node is removed and deleted, head pointer changed
        T remove();
    
        // overload: removes node from list at input index, returns data from removed node
        //           removes last node if given index is out of list range
        // throws exception if list is empty
        // postcond: one node is removed and deleted, head pointer may change
        T remove(const size_t& index);

        // finds node with same input data, returns index of found node
        // returns static_cast<size_t>(-1) if not found
        // precond: data overloaded operator==
        size_t search(const T& data) const;

        // finds node with same input member data, returns index of found node
        // returns static_cast<size_t>(-1) if not found
        // precond: data member overloaded operator==
        template <typename M>
        size_t search(const M T::*member, const M& value) const;

        // prints entire list, returns true if list contains elements to be printed
        // precond: data overloaded operator<<
        bool printList() const;

    private:
        Node<T>* head;
        size_t size;

};

#include "LinkedList.tpp"

#endif