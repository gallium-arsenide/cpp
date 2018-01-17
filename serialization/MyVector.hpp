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
