#include <malloc.h>
#include <map>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

// #include "Class.hpp"

static void my_init_hook(void);
static void *my_malloc_hook(size_t, const void *);
static void my_free_hook(void *, const void *);
/* Variables to save original hooks. */
static void *(*old_malloc_hook)(size_t, const void *);
static void (*old_free_hook)(void *, const void *);

std::map<void*, int> *gMemory;

static void my_init_hook(void){
    old_malloc_hook = __malloc_hook;
    __malloc_hook = my_malloc_hook;

    old_free_hook = __free_hook;
    __free_hook = my_free_hook;
}

static void * my_malloc_hook(size_t size, const void *caller){
    void *result;
    /* Restore all old hooks */
    __malloc_hook = old_malloc_hook;
    /* Call recursively */
    result = malloc(size);
    /* Save underlying hooks */
    old_malloc_hook = __malloc_hook;

    std::cout<<"allo "<<result<<std::endl;
    (*gMemory)[result] += 1;
    /* printf() might call malloc(), so protect it too. */
    // printf("malloc(%u) called from %p returns %p\n",
            // (unsigned int) size, caller, result);
    // cout<<&__malloc_hook<<" "<<&old_malloc_hook<<endl;
    /* Restore our own hooks */
    __malloc_hook = my_malloc_hook;
    return result;
}

void my_free_hook(void *ptr, const void *caller){
    /* Restore all old hooks */
    __free_hook = old_free_hook;
    /* Call recursively */
    free(ptr);
    /* Save underlying hooks */
    old_free_hook = __free_hook;

    std::cout<<"free "<<ptr<<std::endl;
    (*gMemory)[ptr] -= 1;

    // gPointers->insert(result);
    /* printf() might call malloc(), so protect it too. */
    // printf("malloc(%u) called from %p returns %p\n",
            // (unsigned int) size, caller, result);
    // cout<<&__malloc_hook<<" "<<&old_malloc_hook<<endl;
    /* Restore our own hooks */
    __free_hook = my_free_hook;
}



struct MallocTest : testing::Test {
    std::map<void*, int> memory;
    MallocTest(){
        gMemory = &memory;
    }
    virtual void SetUp() {
        my_init_hook();
    }

    virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
        __malloc_hook = old_malloc_hook;
        __free_hook = old_free_hook;

        for(auto &it : memory){
            EXPECT_EQ(it.second, 0);
        }
    }

    virtual ~MallocTest(){
        gMemory = nullptr;
    }
};

TEST_F( MallocTest, VectorMemoryAllocation){
    std::vector<int> * v = new std::vector<int>;
    v->push_back(1);
    v->push_back(2);
    v->push_back(3);
    v->pop_back();
    auto it = v->begin();
    v->insert(it, 8);
    v->clear();
    delete v;

    int * i = new int[10];
    double * d = new double;
    free (i);
    free(d);

}



int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
