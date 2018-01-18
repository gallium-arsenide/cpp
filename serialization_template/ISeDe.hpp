//
//  ISeDe.hpp
//  serialization_template
//
//  Created by <author> on 17/01/2018.
//
//

#ifndef ISeDe_hpp
#define ISeDe_hpp

// Interface for Serialization and deserialization class
class ISeDe {
public:
    virtual ~ISeDe(){};
    virtual void serialize( void * ) = 0;
    virtual void deserialize( void * ) = 0;
    virtual int bytes() = 0;
};


#endif /* ISeDe_hpp */
