//
//  class.hpp
//  class_cpp11
//
//  Created by <author> on 17/01/2018.
//
//

#ifndef class_hpp
#define class_hpp

class A{
public:
    A();
    A(const A&);
    virtual ~A();

    A& operator=(const  A&);

    A(A&&);
    A& operator=(A&&);

    void set(int);
    int get();

private:
    int* a;
};

A fun();

#endif /* class_hpp */
