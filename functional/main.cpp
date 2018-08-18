#include <algorithm>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

/* a function object class */
struct MyCallableClass {
  int operator()(int x) {return x/3;}
};

/* A class with a member function */
struct MyClass {
  int value;
  int member() {return value/5;}
};

int half(int x) {return x/2;}
double my_divide (double x, double y) {return x/y;}

void CallHalf(std::function<int(int)> fn1)
{
    std::cout << "fn1(120): " << fn1(120) << std::endl;
}

void FunctionExamples()
{
    /* Fonction class example */
    std::function<int(int)> fn1 = half;
    std::cout << "fn1(60): " << fn1(60) << std::endl;

    /* We can pass the fonction object to a function */
    CallHalf(fn1);

    /* Also work with member function */
    std::function<int(MyClass&)> member = &MyClass::member;
    MyClass sixty {60};
    std::cout << "fifth(sixty): " << member(sixty) << std::endl;

    /* Work with a callable object */
    std::function<int(int)> callable = MyCallableClass();
    std::cout << "callable(60): " << callable(60) << std::endl;

    /* Example with a Lambda */
    std::function<int(int)> lambda = [](int x){return x/4;};
    std::cout << "lambda(60): " << lambda(60) << std::endl;
}

void BindExamples()
{
    /* Needed to use the placeholders */
    using namespace std::placeholders;

    /* Bind a function with 2 params */
    auto allParams = std::bind (my_divide, 10, 2);
    std::cout << allParams() << std::endl;

    /* Bind only one param. Use a placeholders for the others*/
    auto halfParams = std::bind (my_divide, _1, 2);
    std::cout << halfParams(10) << std::endl;

    /* Use no binding and invert params. Need to pass all params */
    auto noneParams = std::bind (my_divide, _2, _1);
    std::cout << noneParams(10,2) << std::endl;

    /* Change return type to int */
    auto returnParams = std::bind<int> (my_divide, _1, _2);
    std::cout << returnParams(10, 3) << std::endl;

    /* Bind to an object */
    MyClass sixty {60};
    auto bindMember = std::bind (&MyClass::member, sixty);
    std::cout << bindMember() << std::endl;
}

int main (int argc, char *argv[])
{
    FunctionExamples();
    BindExamples();
    return 0;
}
