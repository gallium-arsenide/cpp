#include <iostream>
#include <vector>
#include "MyVector.hpp"

int main(){

    MyVector v = {5, 2, 1, 1, 3};

    for(auto i : v){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    std::cout<< v.size() <<" "<< v.bytes() << std::endl;

    void * p = nullptr;
    p = std::malloc( 200 );
    v.serialize(p);

    MyVector v2;
    v2.deserialize(p);
    for(auto i : v2){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;


    return 0;
}
