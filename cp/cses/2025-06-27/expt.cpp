#include <chrono>
#include <immintrin.h> // AVX
#include <iostream>
#include <vector>

const size_t N = 10'000'000;

// Non-vectorized addition
void simple_add(const float *a, const float *b, float *result) {
    for (size_t i = 0; i < N; ++i) result[i] = a[i] + b[i];
}

// Vectorized addition using AVX
void avx_add(const float *a, const float *b, float *result) {
    size_t i = 0;
    for (; i + 8 <= N; i += 8) {
        __m256 va = _mm256_load_ps(a + i);
        __m256 vb = _mm256_load_ps(b + i);
        __m256 vr = _mm256_add_ps(va, vb);
        _mm256_store_ps(result + i, vr);
    }
    // Handle remaining elements
    for (; i < N; ++i) result[i] = a[i] + b[i];
}

int main( ) {
    // Allocate aligned memory
    float *a = (float *)aligned_alloc(32, N * sizeof(float));
    float *b = (float *)aligned_alloc(32, N * sizeof(float));
    float *result = (float *)aligned_alloc(32, N * sizeof(float));

    // Initialize arrays
    for (size_t i = 0; i < N; ++i) {
        a[i] = static_cast<float>(i);
        b[i] = static_cast<float>(2 * i);
    }

    // Time simple addition
    auto start1 = std::chrono::high_resolution_clock::now( );
    simple_add(a, b, result);
    auto end1 = std::chrono::high_resolution_clock::now( );
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Simple addition time: " << duration1.count( ) << " seconds\n";

    // Time AVX addition
    auto start2 = std::chrono::high_resolution_clock::now( );
    avx_add(a, b, result);
    auto end2 = std::chrono::high_resolution_clock::now( );
    std::chrono::duration<double> duration2 = end2 - start2;
    std::cout << "AVX vectorized addition time: " << duration2.count( ) << " seconds\n";

    free(a);
    free(b);
    free(result);
    return 0;
}
