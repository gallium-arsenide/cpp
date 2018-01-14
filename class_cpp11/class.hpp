class A{
public:
    A();
    A(const A&);
    ~A();

    A& operator=(const  A&);

    A(A&&);
    A& operator=(A&&);

    void set(int);
    int get();

private:
    int* a;
};

A fun();
