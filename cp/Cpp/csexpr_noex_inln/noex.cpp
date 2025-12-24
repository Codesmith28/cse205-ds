#include <chrono>
#include <iostream>
#include <string>
#include <vector>

struct Order {
    std::string id;

    // Constructor from string
    Order(std::string id_) : id(std::move(id_)) {
    }

    // Move constructor
    Order(Order &&other) noexcept : id(std::move(other.id)) {
    }
};

struct OrderThrows {
    std::string id;

    // Constructor from string
    OrderThrows(std::string id_) : id(std::move(id_)) {
    }

    // Move constructor (not noexcept)
    OrderThrows(OrderThrows &&other) : id(std::move(other.id)) {
    }
};

int main( ) {
    std::vector<Order> vec1;
    std::vector<OrderThrows> vec2;

    vec1.reserve(1'000'000);
    vec2.reserve(1'000'000);

    auto start = std::chrono::high_resolution_clock::now( );
    for (int i = 0; i < 1'000'000; ++i) vec1.emplace_back(std::to_string(i));
    auto mid = std::chrono::high_resolution_clock::now( );
    for (int i = 0; i < 1'000'000; ++i) vec2.emplace_back(std::to_string(i));
    auto end = std::chrono::high_resolution_clock::now( );

    std::cout << "noexcept move:     " << std::chrono::duration<double>(mid - start).count( ) << " sec\n";
    std::cout << "non-noexcept move: " << std::chrono::duration<double>(end - mid).count( ) << " sec\n";
}
