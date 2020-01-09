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
    li A, B, K;
    cin >> A >> B >> K;

    FOR(i, 0, K) {
        if (i % 2 == 0) {
            // 偶数回目なので高橋くん
            if (A % 2 == 1) {
                A = A - 1;
            }
            A = A / 2;
            B = B + A;
        } else {
            // 奇数回目なので青木くん
            if (B % 2 == 1) {
                B = B - 1;
            }            
            B = B / 2;
            A = A + B;

        }
    }

    cout << A << " " << B;
     
    return 0;
}