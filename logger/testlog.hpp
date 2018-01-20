//
//  testlog.hpp
//  logger
//
//  Created by <author> on 20/01/2018.
//
//

#ifndef testlog_hpp
#define testlog_hpp

#define LOG logger::magicLogger()

#include <iostream>
#include <sstream>

namespace logger{
class magicLogger{
private:
    std::stringstream buffer;
public:
    magicLogger();
    ~magicLogger();

    template<typename T>
    magicLogger& operator<<(const T& value){
        buffer<<" "<<value;
        return *this;
    }


};
}

#endif /* testlog_hpp */
