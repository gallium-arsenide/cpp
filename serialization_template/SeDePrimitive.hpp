//
//  SeDePrimitive.hpp
//  serialization_template
//
//  Created by <author> on 17/01/2018.
//
//

#ifndef SeDePrimitive_hpp
#define SeDePrimitive_hpp

#include <cstring>
#include <iostream>

template <typename T>
class SeDePrimitive{
public:
    T obj;

    SeDePrimitive(){};
    SeDePrimitive(const T& t) : obj{t} {};

    // copy constructor, artithletic, assignment operators, comparitions ...

    void serialize( void* ptr ){
        std::memcpy(ptr, &obj, sizeof(obj));
        // *static_cast<T*>(ptr) = obj;
        // *((T*) ptr) = obj;
    };

    void deserialize( void* ptr ){
        std::memcpy(&obj, ptr, sizeof(obj));
        // obj = *static_cast<T*>(ptr);
    };

    int bytes(){
        return sizeof(obj);
    };

};


#endif /* SeDePrimitive_hpp */
