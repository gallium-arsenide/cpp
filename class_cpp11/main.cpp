#include <iostream>
#include <vector>
#include "class.hpp"

int main(){
    std::cout << "create first object" << std::endl;
    A first;
    std::cout << std::endl << "create second object" << std::endl;
    A second;
    std::cout << std::endl << "second = first;" << std::endl;
    second = first;
    std::cout << std::endl << "A third = first;" << std::endl;
    A third = first;

    std::cout << std::endl << "second = A();" << std::endl;
    second = A();

    std::cout << std::endl << "A fourth = A(A(A()));" << std::endl;
    A fourth = A(A(A())); // only one constructor is called (copy ellision)

    std::cout << std::endl << "A fifth = std::move(A());" << std::endl;
    A fifth = std::move(A());

    std::cout << std::endl << "std::vector<A> v;"<<std::endl;
    std::vector<A> v;
    v.reserve(5);

    std::cout << "v.push_back(first);"<<std::endl;
    v.push_back(first);
    std::cout << std::endl << "v.push_back(A());"<<std::endl;
    v.push_back(A());

    std::cout << std::endl << "delete all" << std::endl;
}
