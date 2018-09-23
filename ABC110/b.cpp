#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N, M, X, Y;
    cin >> N >> M >> X >> Y;

    li x[N];
    li y[M];

    FOR(i, 0, N) {
        cin >> x[i];
    }

    FOR(i, 0, M) {
        cin >> y[i];
    }

    // x, y を昇順にソート
    sort(x, x + N);
    sort(y, y + M);

    li xmax = x[N - 1];
    li ymin = y[0];

    if (xmax < ymin && xmax <= Y && ymin > X) {
        // yの最小値がxの最大値よりも大きく
        // Yがxの最大値より大きく、xがyの最小値より小さい場合は戦争回避
        cout << "No War";
    } else {
        cout << "War";
    }



    return 0;
}