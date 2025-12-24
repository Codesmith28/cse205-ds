
#include <chrono>
#include <iostream>

// Normal function
int add(int a, int b) {
    return a + b;
}

// Inline function
inline int inline_add(int a, int b) {
    return a + b;
}

int main( ) {
    volatile int sum1 = 0;
    volatile int sum2 = 0;

    auto start = std::chrono::high_resolution_clock::now( );
    for (int i = 0; i < 100'000'000; ++i) sum1 += add(i, i);
    auto mid = std::chrono::high_resolution_clock::now( );
    for (int i = 0; i < 100'000'000; ++i) sum2 += inline_add(i, i);
    auto end = std::chrono::high_resolution_clock::now( );

    std::cout << "Normal function: " << std::chrono::duration<double>(mid - start).count( ) << " sec\n";
    std::cout << "Inline function: " << std::chrono::duration<double>(end - mid).count( ) << " sec\n";
}
