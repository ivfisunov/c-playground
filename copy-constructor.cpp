//
// Created by Ivan Fisunov on 15.08.2020.
//
#include <iostream>

class A {
public:

    int *i{};

    A() = default;

    explicit A(int j) {
        i = new int{j};
    }

    // copy constructor
    A(const A &other) : i{new int{*other.i}} {
        std::cout << "Copy constructor invoked" << std::endl;
    };

    A &operator=(const A &other) {
        std::cout << "Assignment operator constructor invoked" << std::endl;
        if (this == &other) {
            return *this;
        }
        i = new int{*other.i};
        return *this;
    }
};

void copyConstructorTest() {
    std::cout << "--> Copy Constructor" << std::endl;
    A a1(2);
    A a2 = a1; // copy constructor
    *a2.i = 3;
    A a3{a2}; // copy construction
    *a3.i = 6;
    A a4;
    a4 = a3; // assignment operator constructor
    std::cout << *a1.i << " "
              << *a2.i << " "
              << *a3.i << " "
              << *a4.i << std::endl;
}