#include <iostream>
#include <memory>
#include "classes/Directory.h"
#include <unordered_map>

class Prova{
public:
    virtual ~Prova() {
        std::cout<<"distrutto"<<std::endl;
    }
};
int main(){
    /*D root(std::shared_ptr<D>(nullptr));
    std::shared_ptr<D> child = root.addChild();*/

    std :: shared_ptr < Directory > root = Directory ::getRoot();
    auto alfa = root -> addDirectory( "alfa" );
    root -> addDirectory( "beta" )->addFile( "beta1" , 100 );
    root -> getDir( "beta" ) -> addFile( "beta2" , 200 );
    alfa -> getDir( ".." ) -> ls();
    root -> remove( "beta" );
    root -> ls();
}