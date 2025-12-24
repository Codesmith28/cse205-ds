#include <chrono>
#include <iostream>

// Runtime version
int runtime_square(int x) {
    return x * x;
}

// Constexpr version
constexpr int constexpr_square(int x) {
    return x * x;
}

int main( ) {
    constexpr int x = 42;

    auto start = std::chrono::high_resolution_clock::now( );
    volatile int result1 = 0;
    for (int i = 0; i < 100'000'000; ++i) {
        result1 += runtime_square(x); // evaluated at runtime
    }
    auto mid = std::chrono::high_resolution_clock::now( );
    volatile int result2 = 0;
    for (int i = 0; i < 100'000'000; ++i) {
        result2 += constexpr_square(x); // ideally inlined + const folded
    }
    auto end = std::chrono::high_resolution_clock::now( );

    std::cout << "Runtime square:   " << std::chrono::duration<double>(mid - start).count( ) << " sec\n";
    std::cout << "Constexpr square: " << std::chrono::duration<double>(end - mid).count( ) << " sec\n";
}
