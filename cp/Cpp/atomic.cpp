#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread> // <-- required for std::thread
#include <vector> // <-- required for std::vector

constexpr int NUM_THREADS = 8;
constexpr int INCREMENTS_PER_THREAD = 1'000'000;

void benchmark_atomic( ) {
    std::atomic<int> counter{0};

    auto start = std::chrono::high_resolution_clock::now( );
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back([&]( ) {
            for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
                counter.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    for (auto &t : threads) t.join( );

    auto end = std::chrono::high_resolution_clock::now( );
    std::cout << "[Atomic] Final counter: " << counter.load( ) << ", Time: " << std::chrono::duration<double>(end - start).count( ) << "s\n";
}

void benchmark_mutex_lock_guard( ) {
    int counter = 0;
    std::mutex mtx;

    auto start = std::chrono::high_resolution_clock::now( );
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back([&]( ) {
            for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
                std::lock_guard<std::mutex> lock(mtx);
                ++counter;
            }
        });
    }

    for (auto &t : threads) t.join( );

    auto end = std::chrono::high_resolution_clock::now( );
    std::cout << "[Mutex with lock_guard] Final counter: " << counter << ", Time: " << std::chrono::duration<double>(end - start).count( ) << "s\n";
}

void benchmark_mutex_manual_lock( ) {
    int counter = 0;
    std::mutex mtx;

    auto start = std::chrono::high_resolution_clock::now( );
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back([&]( ) {
            for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
                mtx.lock( );
                ++counter;
                mtx.unlock( );
            }
        });
    }

    for (auto &t : threads) t.join( );

    auto end = std::chrono::high_resolution_clock::now( );
    std::cout << "[Mutex with manual lock] Final counter: " << counter << ", Time: " << std::chrono::duration<double>(end - start).count( ) << "s\n";
}

int main( ) {
    std::cout << "Running benchmark with " << NUM_THREADS << " threads and " << INCREMENTS_PER_THREAD << " increments per thread...\n\n";

    benchmark_atomic( );
    benchmark_mutex_lock_guard( );
    benchmark_mutex_manual_lock( );

    return 0;
}
