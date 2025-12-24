
#include <iostream>
#include <memory>

struct B; // Forward declaration

struct A {
    std::shared_ptr<B> ptrB;
    ~A( ) {
        std::cout << "A destroyed\n";
    }
};

struct B {
    std::shared_ptr<A> ptrA;
    ~B( ) {
        std::cout << "B destroyed\n";
    }
};

int main( ) {
    std::shared_ptr<A> a = std::make_shared<A>( );
    std::shared_ptr<B> b = std::make_shared<B>( );

    std::cout << "Initial use_count:\n";
    std::cout << "a.use_count = " << a.use_count( ) << "\n"; // 1
    std::cout << "b.use_count = " << b.use_count( ) << "\n"; // 1

    a->ptrB = b; // A owns B
    b->ptrA = a; // B owns A — circular reference

    std::cout << "After setting circular reference:\n";
    std::cout << "a.use_count = " << a.use_count( ) << "\n"; // 2 (b->ptrA)
    std::cout << "b.use_count = " << b.use_count( ) << "\n"; // 2 (a->ptrB)

    // When main ends, a and b go out of scope
    // But A and B are not deleted because they still point to each other
}
