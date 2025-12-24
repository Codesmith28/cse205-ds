
#include <chrono>
#include <iostream>

int fast_modulo(int x, int mod) {
    return x & (mod - 1); // only valid if mod is power of 2
}

int slow_modulo(int x, int mod) {
    return x % mod;
}

int main( ) {
    constexpr int N = 1'000'000;
    constexpr int MOD = 1024;

    auto start1 = std::chrono::high_resolution_clock::now( );
    volatile int sum1 = 0;
    for (int i = 0; i < N; ++i) sum1 += fast_modulo(i, MOD);
    auto end1 = std::chrono::high_resolution_clock::now( );

    auto start2 = std::chrono::high_resolution_clock::now( );
    volatile int sum2 = 0;
    for (int i = 0; i < N; ++i) sum2 += slow_modulo(i, MOD);
    auto end2 = std::chrono::high_resolution_clock::now( );

    std::cout << "Bitmask Modulo: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count( ) << " us\n";
    std::cout << "Standard Modulo: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count( ) << " us\n";

    return 0;
}
