#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <math.h>

using namespace std;
#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

li gcd(li a,li b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int main(void) {
    li N, K;
    cin >> N >> K;

    li h[N];
    FOR(i, 0, N) {
        cin >> h[i];
    }

    sort(h, h + N);

    li min = 1 << 30;
    FOR(i, 0, N - K + 1) {
        li diff = h[K + i - 1] - h[i];
        if (diff < min) {
            min = diff;
        }
    }
    cout << min;
    return 0;
}