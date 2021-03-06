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
    li N, A, B;
    cin >> N >> A >> B;
    
    li pay = A * N;
    if (pay < B) {
        cout << pay;
    } else {
        cout << B;
    }
    cout << endl;
    return 0;
}
