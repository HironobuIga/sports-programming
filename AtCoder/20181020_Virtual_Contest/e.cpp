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

int main(void) {
    li N, K;
    cin >> N >> K;

    li a[N], b[N];
    vector<li> power; // power 1つ作るのにかかる時間
    FOR(i, 0, N) {
        cin >> a[i] >> b[i];
        power.push_back(a[i]);
    }

    li totalTime = 0;
    FOR(i, 0, K) {
        li minIt = *min_element(power.begin(), power.end());
        li minIndex = *find(power.begin(), power.end(), minIt);

        totalTime += minIt;
        power[minIndex] += b[minIndex];
    }

    cout << totalTime << endl;
    return 0;
}
