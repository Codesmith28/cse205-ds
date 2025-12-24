#include <iostream>
#include <memory>

class Test {
  public:
    Test( ) {
        std::cout << "Constructor\n";
    }
    ~Test( ) {
        std::cout << "Destructor\n";
    }
};

int main( ) {
    std::shared_ptr<Test> sp = std::make_shared<Test>( );
    std::weak_ptr<Test> wp = sp; // Weak reference

    std::cout << "Use count (shared): " << sp.use_count( ) << "\n";
    std::cout << "Is weak pointer expired? " << wp.expired( ) << "\n";
}
