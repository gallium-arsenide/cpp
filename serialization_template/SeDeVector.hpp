//
//  SeDeVector.hpp
//  serialization_template
//
//  Created by <author> on 17/01/2018.
//
//

#ifndef SeDeVector_hpp
#define SeDeVector_hpp

#include <vector>

template < typename T >
class SeDeVector : public std::vector<T> {
private:
public:
    SeDeVector();
    ~SeDeVector();

    void serialize( void * );
    void deserialize( void * );
    int bytes();
protected:

};


#endif /* SeDeVector_hpp */
