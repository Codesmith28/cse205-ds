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
        std::cout << "Hi from Shared\n";
    }
};

int main( ) {
    std::shared_ptr<Test> ptr1 = std::make_shared<Test>( );
    {
        std::shared_ptr<Test> ptr2 = ptr1; // Shared ownership
        ptr2->greet( );
        std::cout << "Use count: " << ptr1.use_count( ) << "\n";
    } // ptr2 goes out of scope
    std::cout << "Use count after inner block: " << ptr1.use_count( ) << "\n";
} // Now ptr1 is destroyed → Destructor called
