#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

void printArray(vector<int> &arr) {
    // print in pretty format:
    cout << "[";
    for (int i = 0; i < arr.size( ); i++) {
        cout << arr[i];
        if (i != arr.size( ) - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void countSort(vector<int> &arr, int place) {
    vector<int> freq(10, 0);

    // get the freq of each digit at "place"
    for (int i = 0; i < arr.size( ); i++) {
        int digit = (arr[i] / place) % 10;
        freq[digit]++;
    }

    // get the cumulative freq: === position in the output
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    vector<int> output(arr.size( ));

    for (int i = arr.size( ) - 1; i >= 0; i--) {
        int element = arr[i];
        int digit = (element / place) % 10;
        int position = freq[digit] - 1;
        output[position] = element;
        freq[digit]--;
    }

    arr = output;
}

void radixSort(vector<int> &nums) {
    int mx_element = *max_element(nums.begin( ), nums.end( ));
    for (int place = 1; mx_element / place > 0; place *= 10) {
        countSort(nums, place);
    }
}

int main( ) {
    // generate a sequence of random numbers:
    int n = 10;
    vector<int> rand_arr(n);
    for (int i = 0; i < n; i++) rand_arr[i] = rand( ) % 100;

    cout << "Unsorted array: ";
    printArray(rand_arr);

    radixSort(rand_arr);
    sleep(3);

    cout << "Sorted array: ";
    printArray(rand_arr);

    return 0;
}
