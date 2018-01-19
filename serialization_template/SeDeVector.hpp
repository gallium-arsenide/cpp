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
#include <cstring>


template < typename T >
class SeDeVector : public std::vector<T>{
private:
public:
    using std::vector<T>::vector;
    ~SeDeVector(){};

    void serialize( void * ptr ){
        unsigned long int size = this->size();
        std::memcpy(ptr, &size, sizeof(size));

        ptr = static_cast<unsigned long int *>(ptr) + 1;

        for(T& obj: *this){
            obj.serialize(ptr);
            ptr = static_cast<double*>(ptr) + 1;
        }
    };

    void deserialize( void * ptr ){
        unsigned long int size;
        std::memcpy(&size, ptr, sizeof(size));
        this->resize(size);

        ptr = static_cast<unsigned long int *>(ptr) + 1;

        for(T& obj: *this){
            obj.deserialize(ptr);
            ptr = static_cast<double*>(ptr) + 1;//obj.bytes();
        }
    };

    int bytes(){
        int size = sizeof(unsigned long int);
        for(T& obj : *this){
            size += obj.bytes();
        }
        return size;
    };
protected:

};


#endif /* SeDeVector_hpp */
