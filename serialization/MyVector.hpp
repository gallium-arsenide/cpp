//
//  MyVector.hpp
//  serialization
//
//  Created by <author> on 17/01/2018.
//
//

#ifndef MyVector_hpp
#define MyVector_hpp

#include <vector>

class MyVector : public  std::vector<double>{
public:
    using vector<double>::vector;
    // MyVector();
    ~MyVector();

    void serialize( void * );
    void deserialize( void * );
    int bytes();
};


#endif /* MyVector_hpp */
