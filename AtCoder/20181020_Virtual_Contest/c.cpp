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
    string s;
    cin >> s;

    string base = "AKIHABARA";
    li position = 0;

    if (s.length() > base.length()) {
        cout << "NO" << endl;
        return 0;
    }

    FOR(i, 0, base.length()) {
        if (position == s.length()) {
            if (i < 8) {
                cout << "NO" << endl;
                return 0;
            }
            break;
        }

        if (base[i] != s[position]) {
            // AKIHABARAとは別の文字が紛れている
            if (base[i] == 'A') {
                // A は追加可能なためセーフ
                continue;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            position += 1;
            continue;
        }
    }

    cout << "YES" << endl;
    return 0;
}
