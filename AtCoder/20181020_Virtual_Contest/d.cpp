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

// Pは親をさす
// したがってPを追っていくことでネットワーク構成がわかる

int main(void) {
    li M, N;
    cin >> M >> N;

    li B[M];
    li C[M];
    li P[N - 1];
    li PPac[N - 1]; // Pに繋がっているpackの数

    FOR(i, 0, N - 1) {
        cin >> P[i];
        PPac[i] = 0;
    }

    FOR(i, 0, M) {
        cin >> B[i] >> C[i];
    }
    
    // Bを見ていく
    FOR(machine, 0, M) {
        li c = B[machine]; // 親の機器を見る
        
    }

    return 0;
}
