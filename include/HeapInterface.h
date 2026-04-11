// HeapInterface.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Pure abstract interface for the ADT max-heap.
// Modeled on the textbook's HeapInterface (Chapter 17, Listing 17-1).
//
// DO NOT MODIFY THIS FILE.

#ifndef HEAP_INTERFACE_H
#define HEAP_INTERFACE_H

template<class T>
class HeapInterface
{
public:

    virtual ~HeapInterface() {}

    /** Returns true if the heap contains no items. */
    virtual bool isEmpty() const = 0;

    /** Returns the number of items currently in the heap. */
    virtual int getNumberOfNodes() const = 0;

    /** Returns the height of the heap.
        An empty heap has height 0.
        For n > 0, height = floor(log2(n)) + 1. */
    virtual int getHeight() const = 0;

    /** Returns the item at the root of the heap (the maximum item).
        @pre  The heap is not empty.
        @post The heap is unchanged.
        @throw EmptyHeapException if the heap is empty. */
    virtual T peekTop() const = 0;

    /** Inserts a new item into the heap and restores the heap property.
        @param newData  The item to insert.
        @return True if the insertion was successful, false if the heap is full. */
    virtual bool add(const T& newData) = 0;

    /** Removes the root item (the maximum) from the heap and restores the heap property.
        @return True if the removal was successful, false if the heap is empty. */
    virtual bool remove() = 0;

    /** Removes all items from the heap. */
    virtual void clear() = 0;

}; // end HeapInterface

#endif
