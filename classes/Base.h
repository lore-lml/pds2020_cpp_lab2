#pragma once
#include <string>

class Base {
    std::string name;

protected:
    Base(const std::string &name) : name(name) {}

public:
    std::string getName() const{
        return name;
    }
    virtual int mType () const = 0;
    virtual void ls (int indent) const = 0;
};

