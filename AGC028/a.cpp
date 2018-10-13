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
    li N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    // 最小公倍数を出す
    li lcmNum = N * M / gcd(N, M);

    // 1文字目は同じでなければならない
    if (S[0] != T[0]) {
        cout << -1 << endl;
        return 0;
    }

    // 片方がもう片方の約数の場合
    if (N % M == 0 || M % N == 0) {
        if ( N > M) {
            li step = N / M;
            bool isNone = false;
            FOR(i, 0, M) {
                if (T[i] != S[step * i]) {
                    isNone = true;
                }
            }
            cout << (isNone ? -1 : N);
            return 0;
        } else {
            li step = M / N;
            bool isNone = false;
            FOR(i, 0, N) {
                if (S[i] != T[step * i]) {
                    isNone = true;
                }
            }
            cout << (isNone ? -1 : M);
            return 0;
        }
    }

    // それ以外
    li stepS = lcmNum / M;
    li stepT = lcmNum / N;
    li lcmSecond = (stepS * stepT) / gcd(stepS, stepT);
    bool isNone = false;
    for(int i = 0; i < lcmNum / lcmSecond; i++) {
        if (S[i * (lcmNum / M)] != T[i * (lcmNum / N)]) {
            isNone = true;
            break;
        }
    }
    if (isNone) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << lcmNum << endl;
        return 0;
    }
}