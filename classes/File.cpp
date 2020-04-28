#include <iostream>
#include "File.h"

File::File(const std::string &name, uintmax_t size): Base(name), size(size){}

void File::ls(int indent) const {
    std::string ind;
    for(int i = 0; i<indent; i++)
        ind += " ";

    std::cout<<ind<<getName()<<" "<<std::to_string(size)<<std::endl;
}

uintmax_t File::getSize() const {
    return size;
}

std::shared_ptr<File> File::create_file(const std::string &name, uintmax_t size) {
    return std::shared_ptr<File>(new File(name, size));
}

int File::mType() const {
    return 1;
}
