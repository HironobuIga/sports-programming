#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <math.h>
#include <map>

using namespace std;
#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

// ユークリッドの互除法
li gcd(li a,li b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

// 素数判定
bool isPrime(li n) {
    for(li i = 0; i * i < n ; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // 1は例外
}

// 素因数分解
map<li, li> prime_factor(li n) {
    map<li, li> res;
    FOR(i, 0, sqrt(n)) {
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}
 
int main(void) {
        li N, M;
    cin >> N >> M;

    li X[M];
    FOR(i, 0, M) {
        cin >> X[i];
    }

    sort(X, X + M);
    
    // 例外処理 N >= M の場合初期配置で全て埋められる
    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }

    // 以下では N < M が保証されるため、全ての点がうまることはない

    // 座標の移動は一方向に絞られる
    // 移動幅が大きい所の両端に点を置く
    // 点が置かれた幅部分はチェックを打っていき、残った幅部分を全てたすと解
    li diffs[M - 1];
    FOR(i, 0, M - 1) {
        diffs[i] = X[i + 1] - X[i];
    }
    
    sort(diffs, diffs + (M - 1));
    li sum = 0;
    FOR(i, 0, M - N) {
        sum += diffs[i];
    }

    cout << sum;

    return 0;
}
