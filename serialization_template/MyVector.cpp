#include "MyVector.hpp"

#include <cstdlib>
#include <cstring>

// MyVector::MyVector(){}
MyVector::~MyVector(){}

void MyVector::serialize( void * ptr ){
    unsigned long int s = size();
    std::memcpy(ptr, &s, sizeof(s));
    ptr = static_cast<unsigned long int *>(ptr)+1;
    std::memcpy(ptr, data(), bytes());
}

void MyVector::deserialize( void * ptr ){
    unsigned long int s;
    std::memcpy(&s, ptr, sizeof(s));
    resize(s);
    ptr = static_cast<unsigned long int *>(ptr)+1;
    std::memcpy(data(), ptr, bytes());
}

int MyVector::bytes(){
    return size() * sizeof(double) + sizeof(int);
}
