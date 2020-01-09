#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N;
    cin >> N;

    li ans = 0;

    FOR(i, 1, N+1) {
        li count = 0;
        if ( i % 2 == 0) {
            continue;
        }

        FOR(j, 1 , i+1) {
            if (i % j == 0) { 
                count++; 
            };
        }
        if (count == 8) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}