// Process.cpp
// CS 302 – Project 4: OS Priority Scheduler
//
// TODO: Implement all Process methods below.
//       This file is provided as a pattern — your two additional
//       item types should follow the same structure.

#include "Process.h"

// ---------------------------------------------------------
// Default constructor
// ---------------------------------------------------------
Process::Process() : name_(""), id_(0), priority_(0)
{
}

// ---------------------------------------------------------
// Parameterized constructor
// ---------------------------------------------------------
Process::Process(const std::string& name, int id, int priority)
    : name_(name), id_(id), priority_(priority)
{
}

// ---------------------------------------------------------
// Accessors
// ---------------------------------------------------------
std::string Process::getName() const
{
    return name_;
}

int Process::getId() const
{
    return id_;
}

int Process::getPriority() const
{
    return priority_;
}

// ---------------------------------------------------------
// operator<  — compares by priority_.
//   If this->priority_ < rhs.priority_, then rhs is more urgent.
//   The heap uses this to keep higher-priority items near the root.
// ---------------------------------------------------------
bool Process::operator<(const Process& rhs) const
{
    return priority_ < rhs.priority_;
}

// ---------------------------------------------------------
// operator==  — compares by priority_.
// ---------------------------------------------------------
bool Process::operator==(const Process& rhs) const
{
    return priority_ == rhs.priority_;
}

// ---------------------------------------------------------
// operator<<  — prints the process in a readable format.
// ---------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Process& p)
{
    os << "[Process] id=" << p.id_
       << " name=" << p.name_
       << " priority=" << p.priority_;
    return os;
}
