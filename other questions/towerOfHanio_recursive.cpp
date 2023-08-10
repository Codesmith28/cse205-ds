#include <iostream>
using namespace std;

// global variable to count the number of steps
int x = 0;

void hanoi(int n, char sou, char dest, char help)
{
    if (n == 0)
    {
        return;
    }

    // first move all from source to helper as in the problem of 2 discs
    hanoi(n - 1, sou, help, dest);

    cout << "Move disc " << n << " from " << sou << " to " << dest << endl;
    x++;

    // at last the source disc will be empty and all discs will be on helper
    // hence the source will act as helper and helper will act as source
    hanoi(n - 1, help, dest, sou);
}

int main()
{
    cout << "Enter the number of discs: " << endl;

    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');

    cout << "Total number of steps: " << x << endl;
    // cout << "Total number of steps: " << (1<<n)- 1 << endl;
    return 0;
}