//
//  SomeClass.cpp
//  diamond_problem
//
//  Created by <author> on 13/01/2018.
//
//

#include "SomeClass.hpp"

#include <iostream>

SomeClass::SomeClass()  {}
SomeClass::~SomeClass() {}

void SomeClass::virtualMethod(){
    std::cout << "I am method of SomeClass" << std::endl;
}
