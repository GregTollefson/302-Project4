#ifndef PRINT_JOB_H
#define PRINT_JOB_H

#include "Comparable.h"
#include <string>
#include <iostream>

class PrintJob : public Comparable<PrintJob>
{
private:
    std::string name_;
    int id_;
    int priority_;

public:
    // Default constructor
    PrintJob();

    // Parameterized constructor
    PrintJob(const std::string& name, int id, int priority);

    // Accessors
    std::string getName() const;
    int getId() const;
    int getPriority() const;

    // Comparable interface
    bool operator<(const PrintJob& rhs) const override;
    bool operator==(const PrintJob& rhs) const override;

    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const PrintJob& p);

};

#endif