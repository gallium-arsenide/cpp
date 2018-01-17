//
//  SeDePrimitive.hpp
//  serialization_template
//
//  Created by <author> on 17/01/2018.
//
//

#ifndef SeDePrimitive_hpp
#define SeDePrimitive_hpp

template <typename T>
class SeDePrimitive{
private:
public:
    T obj;

    int bytes(){ return sizeof(obj); };
protected:

};


#endif /* SeDePrimitive_hpp */
