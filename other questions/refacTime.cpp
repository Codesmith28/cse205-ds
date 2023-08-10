#include <bits/stdc++.h>
using namespace std;

#define int long long

int refactV1(int n)
{
    // calculate factorial using recursion:
    if (n == 1)
        return 1;
    else
        return n * refactV1(n - 1);
}

int refactV2(int n)
{
    // calculate factorial using iteration:
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int refactV3(int n)
{
    // calculate the factorial using recursion:
    if (n == 1 || n == 0)
        return 1;
    else
        return n * refactV3(n - 1);
}

int refactV4(int n)
{
    // calculate the factorial using recursion:
    if (n == 0 || n == 1)
        return 1;
    else
        return n * refactV4(n - 1);
}

int32_t main()
{
    cout << "Enter the number to find the factorial of: " << endl;
    int n;
    cin >> n;

    cout << "Using which method? : ";
    int method;
    cin >> method;

    time_t start, end;
    double time_taken;

    switch (method)
    {
    case 1:
        time(&start);
        cout << "Factorial: " << refactV1(n) << endl;
        time(&end);
        time_taken = double(end - start);
        break;
    case 2:
        time(&start);
        cout << "Factorial: " << refactV2(n) << endl;
        time(&end);
        time_taken = double(end - start);
        break;
    case 3:
        time(&start);
        cout << "Factorial: " << refactV3(n) << endl;
        time(&end);
        time_taken = double(end - start);
        break;
    default:
        cout << "Invalid method number. Exiting..." << endl;
        return 0;
    }

    cout << "Time taken by program is: " << fixed << setprecision(10) << time_taken << " sec" << endl;
    return 0;
}
