// heapSort.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Standalone trickle-down helper and heapSort template function.
//
// DESIGN NOTE:
//   trickleDown() is a free function that operates on any plain array.
//   Both heapSort() (below) and ArrayMaxHeap::heapRebuild() call it,
//   so the trickle-down algorithm is written exactly once.
//
//   This is the key design insight of the project: extract the algorithm
//   into a reusable free function rather than duplicating it.

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <utility>  //needed for std::swap

// -----------------------------------------------------------------
// trickleDown
//
// Restores the max-heap property for a semiheap rooted at `index`.
// A semiheap is a complete binary tree whose root may violate the
// heap property, but whose left and right subtrees are valid heaps.
//
// Uses operator< to compare items.  If parent < child, the child
// has higher priority and should be swapped upward (toward the root).
//
// @param arr   The array representing the heap.
// @param index The root of the semiheap to repair.
// @param size  The number of elements in the heap portion of the array.
// -----------------------------------------------------------------
template<class T>
void trickleDown(T arr[], int index, int size)
{
    // TODO: Implement trickle-down logic here.
    //
    // 1. Find the left child (2*index + 1) and right child (2*index + 2).
    // 2. If no children exist (left >= size), stop.
    // 3. Find the larger child.
    // 4. If arr[index] < largerChild, swap them and recurse (or loop)
    //    on the child's position.
    // 5. Otherwise, the heap property holds — stop.
    while(true)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2; 

        // Case for no children
        if (leftChild >= size)
        {
            break;
        }

        //Assume left child is larger to start
        int largerChild = leftChild;

        //Use right child if it's larger 
        if(rightChild < size && arr[largerChild] < arr[rightChild])
        {
            largerChild = rightChild;
        }

        //swap if parent is smaller than the larger child
        if (arr[index] < arr[largerChild])
        {
            std::swap(arr[index], arr[largerChild]);
            index = largerChild;
        }
        else
        {
            break;
        }

    }
}

// -----------------------------------------------------------------
// heapSort
//
// Sorts a plain array in ascending order using the heap sort algorithm.
// Does NOT use ArrayMaxHeap — operates directly on the array.
//
// @param arr  The array to sort.
// @param size The number of elements in the array.
// -----------------------------------------------------------------
template<class T>
void heapSort(T arr[], int size)
{
    // TODO: Phase 1 — Build a max-heap.
    //   Call trickleDown for each non-leaf node, starting from the
    //   last parent (size/2 - 1) down to index 0.

    // TODO: Phase 2 — Sort.
    //   Repeatedly swap arr[0] (the max) with the last unsorted element,
    //   shrink the heap size by 1, and call trickleDown(arr, 0, newSize).
}

#endif
