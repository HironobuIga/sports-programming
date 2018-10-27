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

    string s;
    cin >> s;
    li foreignPassed = 0;
    li passed = 0;

    FOR(i, 0, s.length()) {
        if (s[i] == 'a') {
            // 国内
            if (passed < (A + B)) {
                cout << "Yes" << endl;
                passed += 1;
            } else {
                cout << "No" << endl;
            }
        } else if (s[i] == 'b') {
            // 海外
            if (passed < A + B && foreignPassed < B) {
                cout << "Yes" << endl;
                passed += 1;
                foreignPassed += 1;
            } else {
                cout << "No" << endl;
            }
        } else {
            // neither
            cout << "No" << endl;
        }
    }

    return 0;
}
