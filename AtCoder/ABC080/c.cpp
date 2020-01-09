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
    li N;
    cin >> N;
    li F[N][5][2];
    FOR(i, 0, N) {
        FOR(j, 0, 5) {
            FOR(k, 0, 2) {
                cin >> F[i][j][k];
            }
        }
    }

    li P[N][11];
    FOR(i, 0, N) {
        FOR(j, 0, 11) {
            cin >> P[i][j];
        }
    }

    li value = -(1ll << 60); // 負の大きい数
    FOR(i, 1, 1024) {
        // 2 ^ 10ケースを確認する
        li o[10];
        FOR(j, 0, 10) {
            o[j] = (i & (1 << j)) > 0 ? 1 : 0;
        }

        li count[N];
        FOR(j, 0, N) {
            count[j] = 0; // 初期化
        }
        FOR(j, 0, N) {
            FOR(k, 0, 10) {
            count[j] += o[k] * F[j][k / 2][k % 2]; // 同時に空いている個数を足す
            }
        }

        li tempValue = 0;
        FOR(j, 0, N) {
            tempValue += P[j][count[j]];
        }
        value = max(tempValue, value);
    }
    
    cout << value << endl;
    return 0;
}
