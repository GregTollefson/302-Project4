#ifndef NETWORK_PACKET_H
#define NETWORK_PACKET_H

#include "Comparable.h"
#include <string>
#include <iostream>

class NetworkPacket : public Comparable<NetworkPacket>
{
private:
    std::string name_;
    int id_;
    int priority_;

public:
    NetworkPacket();
    NetworkPacket(const std::string& name, int id, int priority);

    std::string getName() const;
    int getId() const;
    int getPriority() const;

    bool operator<(const NetworkPacket& rhs) const override;
    bool operator==(const NetworkPacket& rhs) const override;

    friend std::ostream& operator<<(std::ostream& os, const NetworkPacket& p);
};

#endif