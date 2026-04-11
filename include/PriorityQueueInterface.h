// PriorityQueueInterface.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Pure abstract interface for the ADT priority queue.
// Your PriorityQueue<T> must inherit from this interface
// and implement all four methods.
//
// DO NOT MODIFY THIS FILE.

#ifndef PRIORITY_QUEUE_INTERFACE_H
#define PRIORITY_QUEUE_INTERFACE_H

template<class T>
class PriorityQueueInterface
{
public:

    virtual ~PriorityQueueInterface() {}

    /** Returns true if the priority queue contains no items. */
    virtual bool isEmpty() const = 0;

    /** Adds a new item to the priority queue.
        @param newEntry  The item to add.
        @return True if the addition was successful, false if the queue is full. */
    virtual bool add(const T& newEntry) = 0;

    /** Removes the highest-priority item from the queue.
        @return True if the removal was successful, false if the queue is empty. */
    virtual bool remove() = 0;

    /** Returns the highest-priority item without removing it.
        @pre  The priority queue is not empty.
        @post The priority queue is unchanged.
        @throw EmptyHeapException if the queue is empty. */
    virtual T peek() const = 0;

}; // end PriorityQueueInterface

#endif
