#include <memory>
#include <gtest/gtest.h>

#include "../SeDePrimitive.hpp"

struct PrimitiveTest : testing::Test {
    SeDePrimitive<int> *first, *second;
    PrimitiveTest(){
        first = new SeDePrimitive<int>(1);
        second = new SeDePrimitive<int>(2);
    }
    virtual ~PrimitiveTest(){
        delete first;
		delete second;
    }
};

TEST_F( PrimitiveTest, Constructor ){
    EXPECT_EQ(1, first->obj);
    EXPECT_EQ(2, second->obj);
}

TEST_F( PrimitiveTest, SeDe ){
    SeDePrimitive<int> other;
    std::unique_ptr<char> ptr( new char[first->bytes()] );

    first->serialize(ptr.get());
    second->deserialize(ptr.get());

    EXPECT_EQ(first->obj, second->obj);
}

TEST( PrimitiveSeDeTest, SeDe ){
    SeDePrimitive<int> a = 5, b;
    std::unique_ptr<char> ptr( new char[a.bytes()] );
    a.serialize(ptr.get());
    b.deserialize(ptr.get());

    EXPECT_EQ(a.obj, b.obj);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
