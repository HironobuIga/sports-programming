#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N;
    cin >> N;

    FOR(i, 1, 10) {
        li criteria = i * 111;
        if (N <= criteria) {
            cout << criteria;
            break;
        }
    }

    return 0;
}