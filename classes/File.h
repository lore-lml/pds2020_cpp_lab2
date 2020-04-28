#pragma once

#include <memory>
#include <string>
#include "Base.h"

class File: public Base {
    uintmax_t size;

protected:
    File(const std::string &name, uintmax_t size);

public:
    static std::shared_ptr<File> create_file(const std::string& name, uintmax_t size);
    uintmax_t getSize () const;
    void ls (int indent) const override;

    int mType() const override;
};
