#include<bits/stdc++.h>
using namespace std;

int main()  
{
    vector<int> arr = { 31, 28, 19, 4, 60, 2, 29, 22, 39 };
    int k = 30;
    int n = arr.size();

    int maxSize = 0;
    int currentSize = 0;
    int closed = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            currentSize++;
            closed++;
            maxSize = max(maxSize, currentSize);
        } else {
            currentSize = 0;
        }
    }
    
    cout << "Swaps required: " << closed - maxSize << endl;
    return 0;
}
