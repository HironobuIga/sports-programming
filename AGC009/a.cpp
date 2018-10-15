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
    li A[N], B[N];
    FOR(i, 0, N) {
        cin >> A[i] >> B[i];
    }
    
    li count = 0;
    FOR(i, 0, N) {
        li left = (A[N - i -1] + count) % B[N - i - 1];
        if (left == 0) {
            continue;
        } else {
            count += B[N - i - 1] - left;
        }
    }
    cout << count;
    cout << endl;
    return 0;
}
