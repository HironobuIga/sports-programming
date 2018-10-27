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
    li A[N];
    li B[N]; // 解答出力用
    FOR(i, 0, N) {
        cin >> A[i];
        B[i] = 0;
    }
    // 昇順にソート
    sort(A, A + N);

    li base;
    if (N % 2 == 0) {
        base = N / 2 - 1;
    } else {
        base = N / 2;
    }

    FOR(i, 0, N) {
        // 小さい順に入れてく
         if (i == 0) {
            B[base] = A[i];
        }

        if (i % 2 == 0 && i <= base) {
            B[base + i] = A[i];
        } else if (i % 2 == 1 && i <= base) {
            B[base - i - 1] = A[i];
        } else if (i % 2 == 0 && i > base) {
            B[base + (N - i)] = A[i];
        } else if (i % 2 == 1 && i > base) {
            B[base - (N - i - 1)] = A[i]; 
        }
    }

    li sum = 0;
    FOR(i, 0, N - 1) {
        sum += max(B[i], B[i + 1]) - min(B[i], B[i + 1]);
    }
    cout << sum;
    
    return 0;
}