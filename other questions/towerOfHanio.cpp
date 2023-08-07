#include <iostream>
using namespace std;

/* blocks arranged as pyramid...small to big
we need to move the entire pyramid from A to C block by block
such that we cannot put a big block on small block and
we can lift one block at a time...
we have places A ,B ,C i.e.
source rod,helper rod,destination rod
 */

void hanoi(int n, char sou, char dest, char help)
{
    if (n == 0)
    {
        return;
    }

    // first move all from source to helper as in the problem of 2 discs
    hanoi(n - 1, sou, help, dest);

    cout << "Move from " << sou << " to " << dest << endl;

    // at last the source disc will be empty and all discs will be on helper
    // hence the source will act as helper and helper will act as source
    hanoi(n - 1, help, dest, sou);
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}