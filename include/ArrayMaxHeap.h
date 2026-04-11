// ArrayMaxHeap.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Array-backed max-heap class template.
// Inherits from HeapInterface<T>.
//
// DESIGN NOTE:
//   heapRebuild() delegates to the standalone trickleDown() function
//   in heapSort.h.  This means the trickle-down algorithm is written
//   once and shared between ArrayMaxHeap and heapSort — no duplication.

#ifndef ARRAY_MAX_HEAP_H
#define ARRAY_MAX_HEAP_H

#include "HeapInterface.h"
#include "EmptyHeapException.h"
#include "heapSort.h"       // provides trickleDown()
#include <cmath>            // for log2 in getHeight()

template<class T>
class ArrayMaxHeap : public HeapInterface<T>
{
private:
    T* items_;              // Dynamically allocated heap array
    int itemCount_;         // Current number of items
    int maxCapacity_;       // Maximum capacity (set by constructor)

protected:
    // ---------------------------------------------------------
    // heapRebuild
    //
    // Restores the heap property for the semiheap rooted at index.
    // Delegates to the standalone trickleDown() so the algorithm
    // is written only once.
    // ---------------------------------------------------------
    void heapRebuild(int index)
    {
        // TODO: Implement.
        //   Call the standalone trickleDown() function (from heapSort.h)
        //   on the items_ array, starting at index, over itemCount_ elements.
        //   This is one line — do not rewrite the trickle-down algorithm here.
    }

public:
    // ---------------------------------------------------------
    // Constructor
    //   Allocates the internal array and initializes member variables.
    // ---------------------------------------------------------
    ArrayMaxHeap(int capacity)
    {
        // TODO: Implement.
        //   1. Allocate a dynamic array of size capacity using new T[capacity]
        //      and assign it to items_.
        //   2. Set itemCount_ to 0.
        //   3. Set maxCapacity_ to capacity.
    }

    // ---------------------------------------------------------
    // Destructor
    //   Frees the dynamically allocated array.
    // ---------------------------------------------------------
    ~ArrayMaxHeap()
    {
        // TODO: Implement.
        //   Free the items_ array using delete[].
    }

    // ---------------------------------------------------------
    // Copying is disabled. ArrayMaxHeap owns a raw pointer and
    // does not implement deep copy semantics. Declaring these
    // as deleted prevents accidental shallow copies that would
    // cause double-free errors.
    // ---------------------------------------------------------
    ArrayMaxHeap(const ArrayMaxHeap&) = delete;
    ArrayMaxHeap& operator=(const ArrayMaxHeap&) = delete;

    // ---------------------------------------------------------
    // isEmpty
    // ---------------------------------------------------------
    bool isEmpty() const override
    {
        // TODO: Implement.
        return true;
    }

    // ---------------------------------------------------------
    // getNumberOfNodes
    // ---------------------------------------------------------
    int getNumberOfNodes() const override
    {
        // TODO: Implement.
        return 0;
    }

    // ---------------------------------------------------------
    // getHeight
    //   Empty heap: 0.  Otherwise: floor(log2(n)) + 1.
    // ---------------------------------------------------------
    int getHeight() const override
    {
        // TODO: Implement.
        return 0;
    }

    // ---------------------------------------------------------
    // peekTop
    //   @pre Heap is not empty.
    //   @throws EmptyHeapException if the heap is empty.
    // ---------------------------------------------------------
    T peekTop() const override
    {
        // TODO: Implement.
        //   If empty, throw EmptyHeapException("peekTop() called on empty heap");
        //   Otherwise, return items_[0].
        //
        //   Tip: implement this alongside add() so you can test as you go.
        throw EmptyHeapException("peekTop() called on empty heap");
    }

    // ---------------------------------------------------------
    // add
    //   Inserts newData at the end and trickles up.
    //   Returns false if the heap is at capacity.
    // ---------------------------------------------------------
    bool add(const T& newData) override
    {
        // TODO: Implement.
        //   1. If at capacity, return false.
        //   2. Place newData at items_[itemCount_].
        //   3. Trickle up: starting at index itemCount_, compare with
        //      parent at (i-1)/2, swap if the new item has higher
        //      priority (parent < child), and move up. Repeat until
        //      the item reaches the root or its parent is not smaller.
        //   4. Increment itemCount_.
        //   5. Return true.
        //
        //   Note: save itemCount_ to a variable before the loop —
        //   you need it as the starting index, and itemCount_ should
        //   not change until step 4.
        return false;
    }

    // ---------------------------------------------------------
    // remove
    //   Replaces root with last item and calls heapRebuild(0).
    //   Returns false if the heap is empty.
    // ---------------------------------------------------------
    bool remove() override
    {
        // TODO: Implement.
        //   1. If empty, return false.
        //   2. Replace items_[0] with items_[itemCount_ - 1].
        //   3. Decrement itemCount_.
        //   4. Call heapRebuild(0) to restore the heap property.
        //   5. Return true.
        return false;
    }

    // ---------------------------------------------------------
    // clear
    // ---------------------------------------------------------
    void clear() override
    {
        // TODO: Implement.
        //   1. Overwrite each occupied slot with a default-constructed T
        //      to erase stale data (best practice — don't leave old values
        //      sitting in memory after a logical delete).
        //   2. Reset the item count to 0.
    }
};

#endif
