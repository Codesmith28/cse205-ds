
#include <bitset>
#include <chrono>
#include <iostream>

#define FLAG_BUY  (1 << 0)
#define FLAG_SELL (1 << 1)
#define FLAG_HALT (1 << 2)

int main( ) {
    constexpr int iterations = 1'000'000;

    // Bitfield Approach
    auto start1 = std::chrono::high_resolution_clock::now( );
    uint8_t flags = 0;
    for (int i = 0; i < iterations; ++i) {
        flags |= FLAG_BUY;
        bool is_buy = flags & FLAG_BUY;
        flags &= ~FLAG_BUY;
    }
    auto end1 = std::chrono::high_resolution_clock::now( );

    // std::bitset Approach
    auto start2 = std::chrono::high_resolution_clock::now( );
    std::bitset<8> bflags;
    for (int i = 0; i < iterations; ++i) {
        bflags.set(0);
        bool is_buy = bflags.test(0);
        bflags.reset(0);
    }
    auto end2 = std::chrono::high_resolution_clock::now( );

    std::cout << "Bitfield time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count( ) << " ns\n";
    std::cout << "std::bitset time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count( ) << " ns\n";

    return 0;
}
