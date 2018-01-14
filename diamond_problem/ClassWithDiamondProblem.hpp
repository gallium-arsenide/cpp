//
//  ClassWithDiamondProblem.hpp
//  diamond_problem
//
//  Created by <author> on 13/01/2018.
//
//

#ifndef ClassWithDiamondProblem_hpp
#define ClassWithDiamondProblem_hpp

#include "SomeClass.hpp"
#include "SomeOtherClass.hpp"

class ClassWithDiamondProblem : public SomeClass, public SomeOtherClass{
private:
public:
    ClassWithDiamondProblem();
    ~ClassWithDiamondProblem();
protected:

};


#endif /* ClassWithDiamondProblem_hpp */
