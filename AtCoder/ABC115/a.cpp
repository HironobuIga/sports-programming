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
    li d;
    cin >> d;

    switch (d) {
        case 25:
        cout << "Christmas";
        break;
        case 24:
        cout << "Christmas Eve";
        break;
        case 23:
        cout << "Christmas Eve Eve";
        break;
        case 22:
        cout << "Christmas Eve Eve Eve";
        break;
        default:
        break;
    }

    return 0;
}