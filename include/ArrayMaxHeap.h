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
        trickleDown(items_, index, itemCount_);
    }

public:
    // ---------------------------------------------------------
    // Constructor
    //   Allocates the internal array and initializes member variables.
    // ---------------------------------------------------------
    ArrayMaxHeap(int capacity)
    {
         items_ = new T[capacity];
         itemCount_ = 0;
         maxCapacity_ = capacity;
    }

    // ---------------------------------------------------------
    // Destructor
    //   Frees the dynamically allocated array.
    // ---------------------------------------------------------
    ~ArrayMaxHeap()
    {
        delete[] items_;        
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
        return itemCount_ == 0;
    }

    // ---------------------------------------------------------
    // getNumberOfNodes
    // ---------------------------------------------------------
    int getNumberOfNodes() const override
    {
        return itemCount_;
    }

    // ---------------------------------------------------------
    // getHeight
    //   Empty heap: 0.  Otherwise: floor(log2(n)) + 1.
    // ---------------------------------------------------------
    int getHeight() const override
    {
        if (itemCount_ == 0)
            return 0;

        //log2 returns a double, floor rounds down, stat_cast<int> converts float to int 
        return static_cast<int>(std::floor(std::log2(itemCount_))) + 1;
    }
        

    // ---------------------------------------------------------
    // peekTop
    //   @pre Heap is not empty.
    //   @throws EmptyHeapException if the heap is empty.
    // ---------------------------------------------------------
    T peekTop() const override
    {
        if(isEmpty())
        {
            throw EmptyHeapException("peekTop() called on empty heap");
        }

        return items_[0];

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
        if (itemCount_ >= maxCapacity_)
        {
            return false;
        }
        
        int newIndex = itemCount_;
        items_[newIndex] = newData;

        // Trickle up
        while(newIndex > 0)
        {
            int parentIndex = (newIndex - 1)/2;

            // If parent >= child, stop
            if (!(items_[parentIndex] < items_[newIndex]))
            {
                break;
            }

            // Swap parent and child
            std::swap(items_[parentIndex], items_[newIndex]);
            newIndex = parentIndex;

        }

        itemCount_++;
        return true;
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

        if (isEmpty())
        {
            return false;
        }

        items_[0] = items_[itemCount_ - 1];
        itemCount_--;

        // avoids calling heapRebuild() when heap just became empty
        // after removing the last item 
        if (!isEmpty())  
        {
            heapRebuild(0);
        }

        return true;
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
        for (int i = 0; i < itemCount_; i++)
        {
            items_[i] = T(); //assign a default-constructed object T to items[i];
        }

        itemCount_ = 0;
    }
};

#endif
