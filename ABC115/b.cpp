#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <math.h>

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
    li p[N];

    li max = 0;
    li index = 0;
    FOR(i, 0, N) {
        cin >> p[i];
        if (p[i] > max) {
            max = p[i];
            index = i;
        }
    }

    p[index] = max / 2;
    li sum = 0;
    FOR(i, 0, N) {
        sum += p[i];
    } 

    cout << sum;

    return 0;
}