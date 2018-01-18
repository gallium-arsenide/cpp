#include <iostream>
#include <vector>

#include "SeDeVector.hpp"
#include "SeDePrimitive.hpp"

int main(){

    SeDeVector< SeDePrimitive<double> > v = {5, 2, 1, 1, 3};
    // v = new SeDeVector< SeDePrimitive<double> >;

    // std::vector<double> * v = new std::vector<double>;
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);


    for(auto& i : v){
        std::cout<<i.obj<<" ";
    }
    std::cout<<std::endl;

    void * p = nullptr;
    p = std::malloc( v.bytes() );

    v.serialize(p);

    SeDeVector< SeDePrimitive<double> > v2;
    v2.deserialize(p);
    for(auto& i : v2){
        std::cout<<i.obj<<" ";
    }
    std::cout<<std::endl;

    free(p);
    return 0;
}
