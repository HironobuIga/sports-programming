#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N;
    cin >> N;

    li C[N + 10];
    li S[N + 10];
    li F[N + 10];

    li ans[N + 10];

    FOR(i, 0, N-1) {
        cin >> C[i] >> S[i] >> F[i];
    }

    FOR(index, 0, N-1) {
        li answer = 0;
        FOR(k, index, N-1) {
            if (answer == 0) {
                // はじめは待ち時間と移動時間のみ追加
                answer = S[k];
                answer += C[k];
                continue;
            }

            if (answer < S[k]) {
                // 列車の運行開始前の場合は開始まで待ち、移動時間を追加
                answer = S[k];
                answer += C[k];
            } else {
                if (answer % F[k] == 0) {
                    // 出発時間ぴったりについた場合
                    answer += C[k];
                } else {
                // 運行開始後の場合は、次の列車を待ち、移動時間を追加
                li multi = answer / F[k];
                li diff = (multi + 1) * F[k] - answer;
                answer += diff + C[k];
                }
            }
        }
        ans[index] = answer;
    }

    FOR(index, 0, N) {
        if (index == N-1) {
            cout << 0 << endl;
        } else {
        cout << ans[index] << endl;
        }
    }

    return 0;
}
