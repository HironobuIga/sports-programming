#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    string S, T;
    cin >> S >> T;
    li N = S.length();

    li s[26];
    li t[26];

    FOR(i, 0, 26) {
        // indexの初期化
        s[i] = 0;
    }

    // 文字列中で同一の文字のindexを探し、
    // S, Tでそのindexがずれるものがあれば一致不可

    // 同一アルファベットの配列箇所をマーク
    for(char c = 'a'; c <= 'z'; c++) {
        li u = 0;
        FOR(i, 0, N) {
            if (S[i] == c) {
                s[u] += i;
            }
            if (t[i] == c) {
                t[u] += i;
             }
        }
        u += 1;
    }

    // 配列が一致しているか確認
    sort(s, s+26);
    sort(t, t+26);

    FOR(i, 0, 26) {
        if (s[i] != t[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}