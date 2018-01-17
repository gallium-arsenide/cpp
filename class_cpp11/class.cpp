//
//  class.cpp
//  class_cpp11
//
//  Created by <author> on 17/01/2018.
//
//

#include <iostream>
#include <utility>
#include "class.hpp"


    A::A(){
        std::cout << "class A constructor" << std::endl;
        a = new int;
    }

    A::A(const A& other){
        std::cout << "class A copy constructor" << std::endl;
        a = new int;
        *a = *(other.a);
    }

    A::~A(){
        std::cout << "class A destructor" << std::endl;
        delete a;
    }

    A& A::operator=(const A &other){
        std::cout << "class A assignment operator" << std::endl;
        *a = *(other.a);
        return *this;
    }

    // since C++11
    A::A(A &&other){
        std::cout << "class A move constructor" << std::endl;
        a = other.a;
        other.a = nullptr;

    }
    A& A::operator=(A &&other){
        std::cout << "class A move assignment operator" << std::endl;
        delete a;
        a = other.a;
        other.a = nullptr;
        return *this;
    }

    void A::set(int val){ *a = val; }
    int A::get(){ return *a; }

A fun(){
    A a;
    a.set(12);
    std::cout<<a.get()<<" "<<&a<<std::endl;
    return a;
}
