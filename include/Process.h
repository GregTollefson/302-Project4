// Process.h
// CS 302 – Project 4: OS Priority Scheduler
//
// Represents a process in a CPU scheduler.
// Priority represents urgency level: higher value = more urgent.
//
// This item type is provided as a pattern for you to follow when
// implementing your two additional item types.
//
// TODO: Finish the implementation in Process.cpp.

#ifndef PROCESS_H
#define PROCESS_H

#include "Comparable.h"
#include <string>
#include <iostream>

class Process : public Comparable<Process>
{
private:
    std::string name_;
    int id_;
    int priority_;

public:
    // Default constructor (needed for arrays in heapSort demo)
    Process();

    // Parameterized constructor
    Process(const std::string& name, int id, int priority);

    // Accessors
    std::string getName() const;
    int getId() const;
    int getPriority() const;

    // Comparable interface
    bool operator<(const Process& rhs) const override;
    bool operator==(const Process& rhs) const override;

    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const Process& p);

}; // end Process

#endif
