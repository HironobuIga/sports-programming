#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;
#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

li gcd(li a,li b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

li N = 0;

inline li dfs(li n) {
    if (n > N) return 0;

    bool hasSeven = false;
    bool hasFive = false;
    bool hasThree = false;
    li a = n;
    while(a > 0) {
        if (a % 10 == 7) { hasSeven = true; };
        if (a % 10 == 5) { hasFive = true; };
        if (a % 10 == 3) { hasThree = true; };
        a = a / 10;
    }
    li ret = (hasSeven && hasFive && hasThree) ? 1 : 0;
    ret += dfs(n * 10 + 7);
    ret += dfs(n * 10 + 5);
    ret += dfs(n * 10 + 3);

    return ret;
}

int main(void) {
    cin >> N;

    li ans = dfs(0);
    cout << ans;

    return 0;
}