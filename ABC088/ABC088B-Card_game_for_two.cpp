#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int card[N];

    for (int i = 0; i < N; ++i) {
        cin >> card[i];
    }

    int Alice = 0;
    int Bob = 0;

    sort(card, card + N, greater<int>()); // 降順ソート 
    for(int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            // 偶数番目はアリスのターン
            Alice = Alice + card[i];
        } else {
            // 奇数番目はボブのターン
            Bob = Bob + card[i];
        }
    }

    int answer = Alice - Bob;

    cout << answer;
    return 0;
}