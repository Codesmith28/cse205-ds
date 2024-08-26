### Solution

- This can be solved by dividing the path from 0 to x in multiples of 5
- As there is no cost associated with the size of step, we can greedily take the largest possible path that is of the size 5
- After dividing by 5, if any segment exist which is smaller than 5, it can be covered using 1 step as all possible paths that remains now are of size [1,4], and as per the question we can make this move in 1 step 

### Code:
```
#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

int main() {
    int x;
    cin >> x;

    int ans = 0;
    ans += x / 5;
    if (x % 5 != 0) ans++;

    cout << ans << endl;
    return 0;
}
```