#pragma once
#include <string>
#include <map>
#include <memory>
#include "Base.h"
#include "File.h"

class Directory: public Base {
    static std::shared_ptr<Directory> root;
    std::map<std::string, std::shared_ptr<Base>> children;
    std::weak_ptr<Directory> parent;
    std::weak_ptr<Directory> self;

protected:
    Directory(const std::string& name);

public:
    static std::shared_ptr<Directory> makeDirectory(const std::string& name, std::weak_ptr<Directory> parent);
    static std::shared_ptr<Directory> getRoot ();

    std::shared_ptr<Base> get(std::string name);
    std::shared_ptr<Directory> addDirectory(const std::string& name);

    virtual int mType() const override;
    virtual void ls(int indent = 0) const override;
    std::shared_ptr<File> addFile (const std::string& nome, uintmax_t size);
    std::shared_ptr<Directory> getDir (const std::string& name);
    std::shared_ptr<File> getFile (const std::string& name);
    bool remove (const std::string& nome);
};