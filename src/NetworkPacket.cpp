#include "NetworkPacket.h"

// Process.cpp
// CS 302 – Project 4: Network Packet Priority Scheduler
//
// TODO: Implement all Process methods below.
//       This file is provided as a pattern — your two additional
//       item types should follow the same structure.



// ---------------------------------------------------------
// Default constructor
// ---------------------------------------------------------
NetworkPacket::NetworkPacket() : name_(""), id_(0), priority_(0) {

}

// ---------------------------------------------------------
// Parameterized constructor
// ---------------------------------------------------------
NetworkPacket::NetworkPacket(const std::string& name, int id, int priority)
    : name_(name), id_(id), priority_(priority)
{
}

// ---------------------------------------------------------
// Accessors
// ---------------------------------------------------------
std::string NetworkPacket::getName() const
{
    return name_;
}

int NetworkPacket::getId() const
{
    return id_;
}

int NetworkPacket::getPriority() const
{
    return priority_;
}

// ---------------------------------------------------------
// operator<  — compares by priority_.
//   If this->priority_ < rhs.priority_, then rhs is more urgent.
//   The heap uses this to keep higher-priority items near the root.
// ---------------------------------------------------------
bool NetworkPacket::operator<(const NetworkPacket& rhs) const
{
    return priority_ < rhs.priority_;
}

// ---------------------------------------------------------
// operator==  — compares by priority_.
// ---------------------------------------------------------
bool NetworkPacket::operator==(const NetworkPacket& rhs) const
{
    return priority_ == rhs.priority_;
}

// ---------------------------------------------------------
// operator<<  — prints the process in a readable format.
// ---------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const NetworkPacket& p)
{
    os << "[NetworkPacket] id=" << p.id_
       << " name=" << p.name_
       << " priority=" << p.priority_;
    return os;
}
