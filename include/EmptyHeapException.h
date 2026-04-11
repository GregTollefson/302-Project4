// EmptyHeapException.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Exception thrown when peekTop() or peek() is called on an empty heap
// or priority queue.
//
// DO NOT MODIFY THIS FILE.

#ifndef EMPTY_HEAP_EXCEPTION_H
#define EMPTY_HEAP_EXCEPTION_H

#include <stdexcept>
#include <string>

class EmptyHeapException : public std::runtime_error
{
public:
    explicit EmptyHeapException(const std::string& message)
        : std::runtime_error(message) {}

}; // end EmptyHeapException

#endif
