// Comparable.h
// CS 302 – Data Structures
//
// Interface for objects that support ordering and equality comparisons.
// Any class stored in a templated ADT (BST, Heap, etc.) that requires
// ordering must inherit from Comparable<T> and implement both operators.
//
// DO NOT MODIFY THIS FILE.

#ifndef COMPARABLE_H
#define COMPARABLE_H

template <class T>
class Comparable
{
public:

    virtual ~Comparable() {}

    /** Returns true if this object is less than rhs.
        @param rhs  The object to compare against.
        @return True if this < rhs; false otherwise. */
    virtual bool operator<(const T& rhs) const = 0;

    /** Returns true if this object is equal to rhs.
        @param rhs  The object to compare against.
        @return True if this == rhs; false otherwise. */
    virtual bool operator==(const T& rhs) const = 0;

};  // end Comparable

#endif
