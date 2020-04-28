#include "Directory.h"
#include <utility>
#include <iostream>

std::shared_ptr<Directory> Directory::root;

Directory::Directory(const std::string& name) : Base(name) {}

std::shared_ptr<Base> Directory::get(std::string name) {
    if(name == ".")
        return self.lock();

    if(name == "..")
        return parent.lock();

    if(children.count(name) > 0)
        return children[name];

    return std::shared_ptr<Directory>();
}

std::shared_ptr<Directory> Directory::makeDirectory(const std::string& name, std::weak_ptr<Directory> parent) {
    std::shared_ptr<Directory> dir(new Directory(name));
    dir->self = dir;
    dir->parent = std::move(parent);
    return dir;
}

std::shared_ptr<Directory> Directory::addDirectory(const std::string& name) {
    if(children.count(name) > 0 || name == "." || name == "..")
        return std::shared_ptr<Directory>();

    auto new_dir = makeDirectory(name, self);
    children[name] = new_dir;
    return new_dir;
}

std::shared_ptr<Directory> Directory::getRoot(){
    if(root == nullptr){
        root = std::shared_ptr<Directory>(new Directory("/"));
        root->self = root;
        root->parent = root;
    }
    return root;
}

int Directory::mType() const {
    return 0;
}

void Directory::ls(int indent) const {
    std::string ind;
    for(int i = 0; i<indent; i++)
        ind += " ";

    std::cout<<ind<<"[+] "<<getName()<<std::endl;

    for (const auto& element : children)
        element.second->ls(indent+6);
}

std::shared_ptr<File> Directory::addFile(const std::string &name, uintmax_t size) {
    if(children.count(name) > 0 || name == ".." || name == ".")
        return std::shared_ptr<File>();

    auto file = File::create_file(name, size);
    children[name] = file;
    return file;
}

std::shared_ptr<Directory> Directory::getDir(const std::string &name) {
    auto dir = get(name);

    if(dir == nullptr || dir->mType() != 0)
        return std::shared_ptr<Directory>();

    return std::dynamic_pointer_cast<Directory>(dir);
}

std::shared_ptr<File> Directory::getFile(const std::string &name) {
    auto file = get(name);

    if(file == nullptr || file->mType() != 1)
        return std::shared_ptr<File>();

    return std::dynamic_pointer_cast<File>(file);
}

bool Directory::remove(const std::string &name) {
    if(name == ".." || name == ".")
        return false;

    return children.erase(name) > 0;
}



