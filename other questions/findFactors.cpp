#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

// to find all the normal factors of a number:
vector<int> normalFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }

    return factors;
}

// to find all the prime factors of a numebr:
vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

int main() {

    cout << "Enter the number: ";
    int n;
    cin >> n;

    vector<int> normal = normalFactors(n);
    vector<int> prime = primeFactors(n);

    for (auto it : normal) {
        cout << it << " ";
    }cout << endl;

    for (auto it : prime) {
        cout << it << " ";
    }cout << endl;

    return 0;
}