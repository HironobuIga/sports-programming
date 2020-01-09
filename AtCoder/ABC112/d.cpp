#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N, M;
    cin >> N >> M;

    vector<li> d;
    li sqrtM = sqrt(M);
    FOR(i, 1, sqrtM + 1) {
        if (M % i == 0) {
            d.push_back(i);
            d.push_back(M / i);
        }
    }

    li answer = 0;
    li upper = M/N;
    sort(d.begin(), d.end());
    for(li x: d) {
        if (x > upper) {
            break;
        }
        answer = x;
    }

    cout << answer << endl;

    return 0;
}