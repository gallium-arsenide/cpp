//
//  testlog.cpp
//  logger
//
//  Created by <author> on 20/01/2018.
//
//

#include "testlog.hpp"

#include <iostream>

using namespace logger;


magicLogger::magicLogger()  {
    buffer<<"[    LOG   ]";
}
magicLogger::~magicLogger() {
    std::cout<<buffer.str()<<std::endl;
}
