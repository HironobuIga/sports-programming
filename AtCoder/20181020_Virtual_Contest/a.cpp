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
    string s, base;
    cin >> s;

    base = "CODEFESTIVAL2016";

    li count;
    FOR(i, 0, s.length()) {
        if (base[i] != s[i]) {
            count += 1;
        }
    }

    cout << count << endl;
    return 0;
}
