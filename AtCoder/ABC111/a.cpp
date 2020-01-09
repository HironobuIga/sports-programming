#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

int main(void) {
    string n;
    cin >> n;

    string ans = "";
    FOR(i, 0, 3) {
        if (n[i] == '1') {
            ans += '9';
        } else {
            ans += '1';
        }
    }
    cout << ans;
    return 0;
}