#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

int main(void) {
    li N[3];
    cin >> N[0] >> N[1] >> N[2];

    sort(N, N + 3);

    cout << N[2] * 10 + N[1] + N[0];

    return 0;
}