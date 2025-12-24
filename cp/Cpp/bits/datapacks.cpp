#include <chrono>
#include <iostream>
#include <stdint.h>

#define N 1000000

// Bit Manipulation Approach
uint64_t pack_order(uint32_t price, uint32_t qty) {
    return ((uint64_t)price << 32) | qty;
}

void unpack_order(uint64_t packed, uint32_t &price, uint32_t &qty) {
    price = packed >> 32;
    qty = packed & 0xFFFFFFFF;
}

// Struct Approach
struct Order {
    uint32_t price;
    uint32_t qty;
};

int main( ) {
    // Benchmark Bit Manipulation
    uint64_t bit_orders[N];
    auto start1 = std::chrono::high_resolution_clock::now( );
    for (int i = 0; i < N; ++i) {
        bit_orders[i] = pack_order(i, i + 10);
    }
    uint32_t total_price1 = 0, total_qty1 = 0;
    for (int i = 0; i < N; ++i) {
        uint32_t price, qty;
        unpack_order(bit_orders[i], price, qty);
        total_price1 += price;
        total_qty1 += qty;
    }
    auto end1 = std::chrono::high_resolution_clock::now( );

    // Benchmark Struct
    Order struct_orders[N];
    auto start2 = std::chrono::high_resolution_clock::now( );
    for (uint32_t i = 0; i < N; ++i) {
        struct_orders[i] = {i, i + 10};
    }
    uint32_t total_price2 = 0, total_qty2 = 0;
    for (int i = 0; i < N; ++i) {
        total_price2 += struct_orders[i].price;
        total_qty2 += struct_orders[i].qty;
    }
    auto end2 = std::chrono::high_resolution_clock::now( );

    std::cout << "Bit Packing Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count( ) << " µs\n";
    std::cout << "Struct Access Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count( ) << " µs\n";

    // Prevent optimizing away
    std::cout << "Totals (bit): " << total_price1 << ", " << total_qty1 << "\n";
    std::cout << "Totals (struct): " << total_price2 << ", " << total_qty2 << "\n";

    return 0;
}
