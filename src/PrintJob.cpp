#include "PrintJob.h"

// Process.cpp
// CS 302 – Project 4: Print Job Priority Scheduler
//
// TODO: Implement all Process methods below.
//       This file is provided as a pattern — your two additional
//       item types should follow the same structure.



// ---------------------------------------------------------
// Default constructor
// ---------------------------------------------------------
PrintJob::PrintJob() : name_(""), id_(0), priority_(0) 
{
}

// ---------------------------------------------------------
// Parameterized constructor
// ---------------------------------------------------------
PrintJob::PrintJob(const std::string& name, int id, int priority)
    : name_(name), id_(id), priority_(priority)
{
}

// ---------------------------------------------------------
// Accessors
// ---------------------------------------------------------
std::string PrintJob::getName() const
{
    return name_;
}

int PrintJob::getId() const
{
    return id_;
}

int PrintJob::getPriority() const
{
    return priority_;
}

// ---------------------------------------------------------
// operator<  — compares by priority_.
//   If this->priority_ < rhs.priority_, then rhs is more urgent.
//   The heap uses this to keep higher-priority items near the root.
// ---------------------------------------------------------
bool PrintJob::operator<(const PrintJob& rhs) const
{
    return priority_ < rhs.priority_;
}

// ---------------------------------------------------------
// operator==  — compares by priority_.
// ---------------------------------------------------------
bool PrintJob::operator==(const PrintJob& rhs) const
{
    return priority_ == rhs.priority_;
}

// ---------------------------------------------------------
// operator<<  — prints the process in a readable format.
// ---------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const PrintJob& p)
{
    os << "[PrintJob] id=" << p.id_
       << " name=" << p.name_
       << " priority=" << p.priority_;
    return os;
}
