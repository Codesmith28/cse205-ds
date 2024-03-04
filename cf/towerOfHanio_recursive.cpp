#include <bits/stdc++.h>
using namespace std;

// global variable to count the number of steps
int x = 0;

void hanoi(int n, char sou, char dest, char help)
{
    if (n == 0)
    {
        return;
    }

    // move top n-1 from source to helper
    hanoi(n - 1, sou, help, dest);

    // move the largest disc from source to destination
    cout << "Move disc " << n << " from " << sou << " to " << dest << endl;
    x++;

    // move the n-1 discs from helper to destination
    hanoi(n - 1, help, dest, sou);
}

int main()
{
    cout << "Enter the number of discs: " << endl;

    int n;
    cin >> n;

    time_t start, end;
    double time_taken;

    time(&start);
    hanoi(n, 'A', 'C', 'B');
    time(&end);

    time_taken = double(end - start);
    cout << "Total number of steps: " << x << endl;
    cout << "Time taken to run: " << time_taken << " sec" << endl;
    // cout << "Total number of steps: " << (1<<n)- 1 << endl;
    return 0;
}