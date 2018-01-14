#include "ClassWithDiamondProblem.hpp"
#include "SomeClass.hpp"
#include "SomeOtherClass.hpp"

int main(){

	ClassWithDiamondProblem obj;

	// obj.virtualMethod(); // request for member ‘virtualMethod’ is ambiguous

	SomeOtherClass *p = &obj;
	p->virtualMethod();
	static_cast<SomeClass>(obj).virtualMethod();


	return 0;
}
