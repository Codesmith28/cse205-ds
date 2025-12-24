#include <chrono>
#include <iostream>
#include <string>

std::string largeObject = "This is a very large string that will be copied many times. "
                          "We want to see how much time copying it takes compared to moving it. "
                          "This string represents a large object and will be used multiple times in the functions.";

void copyExample(std::string obj) {
    // Function that takes the object by value and copies it in each call
    for (int i = 0; i < 1000; ++i) {
        std::string copy = obj; // Create a copy of the large object
    }
}

void moveExample(std::string &&obj) {
    // Function that moves the object instead of copying it
    for (int i = 0; i < 1000; ++i) {
        std::string moved = std::move(obj); // Move the large object
        // After moving, the original object is in an unspecified state
    }
}

int main( ) {
    // Measure the time for copying the object multiple times
    auto start = std::chrono::high_resolution_clock::now( );
    copyExample(largeObject); // Pass the large object by value to create copies
    auto end = std::chrono::high_resolution_clock::now( );
    std::chrono::duration<double> copy_duration = end - start;
    std::cout << "Copying took: " << copy_duration.count( ) << " seconds\n";

    // Measure the time for moving the object multiple times
    start = std::chrono::high_resolution_clock::now( );
    moveExample(std::move(largeObject)); // Pass the large object by rvalue reference for moving
    end = std::chrono::high_resolution_clock::now( );
    std::chrono::duration<double> move_duration = end - start;
    std::cout << "Moving took: " << move_duration.count( ) << " seconds\n";

    std::cout << std::max(1, 2) << "\n";

    return 0;
}
