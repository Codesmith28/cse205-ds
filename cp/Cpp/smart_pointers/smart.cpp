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
    void greet( ) {
        std::cout << "Hello from Test\n";
    }
};

int main( ) {
    std::unique_ptr<Test> ptr = std::make_unique<Test>( );
    ptr->greet( ); // Access the object
} // Destructor is called automatically here
