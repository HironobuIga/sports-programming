#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N, T;
    cin >> N >> T;

    li c[N];
    li t[N];

    FOR(i, 0, N) {
        cin >> c[i] >> t[i];
    }
    li TLECost = 2000;
    li minCost = 2000; // 考えられるコストの上限より大きい数
    FOR(i, 0, N) {
        if (t[i] <= T && c[i] < minCost) {
            minCost = c[i];
        }
    }

    if (minCost == TLECost) {
        cout << "TLE"; 
    } else {
        cout << minCost;
    }

    return 0;
}