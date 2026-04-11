// PriorityQueue.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Priority queue implemented as a thin wrapper around ArrayMaxHeap<T>.
// Inherits from PriorityQueueInterface<T> and uses has-a composition.
//
// DESIGN NOTE:
//   Every method here is a one-liner that forwards to the internal
//   ArrayMaxHeap.  PriorityQueue adds no logic of its own — it only
//   provides the priority-queue vocabulary (peek, add, remove) on top
//   of the heap's interface.

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "PriorityQueueInterface.h"
#include "ArrayMaxHeap.h"
#include "EmptyHeapException.h"

template<class T>
class PriorityQueue : public PriorityQueueInterface<T>
{
private:
    ArrayMaxHeap<T> heap_;

public:
    // ---------------------------------------------------------
    // Constructor — passes capacity through to the heap.
    // ---------------------------------------------------------
    PriorityQueue(int capacity) : heap_(capacity)
    {
    }

    // ---------------------------------------------------------
    // isEmpty
    // ---------------------------------------------------------
    bool isEmpty() const override
    {
        return heap_.isEmpty();
    }

    // ---------------------------------------------------------
    // add
    // ---------------------------------------------------------
    bool add(const T& newEntry) override
    {
        return heap_.add(newEntry);
    }

    // ---------------------------------------------------------
    // remove
    // ---------------------------------------------------------
    bool remove() override
    {
        return heap_.remove();
    }

    // ---------------------------------------------------------
    // peek
    //   Calls heap_.peekTop(). Catches EmptyHeapException and
    //   re-throws with a priority-queue-specific message.
    // ---------------------------------------------------------
    T peek() const override
    {
        // TODO: Call heap_.peekTop() inside a try/catch.
        //   Catch EmptyHeapException and re-throw with:
        //   "peek() called on empty priority queue"
        try
        {
            {
                return heap_.peekTop();
            }
        }
        catch(const EmptyHeapException&)
        {
            throw EmptyHeapException("peek() called on empty priority queue");
        }
    }

    // ---------------------------------------------------------
    // getSize  (not part of the interface — needed by the driver)
    // ---------------------------------------------------------
    int getSize() const
    {
        return heap_.getNumberOfNodes();
    }

}; // end PriorityQueue

#endif
