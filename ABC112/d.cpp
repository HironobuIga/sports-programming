#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; ++i)
#define REP(i, n) FOR(i, 0, n)

// 素因数分解
vector<li> decomposite(li n) {
    li a = 2;
    vector<li> ret;
    while (n >= a * a) {
        if (n % a == 0) {
            n /= a;
            ret.push_back(a);
        } else {
            a += 1;
        }
    }
    return ret;
}
li gdc_euclid(li u, li v) {
    while(v != 0) {
        li r;
        r = u % v; u = v; v = r;
    }
    return u;
}

int main(void) {
    li N, M;
    cin >> N >> M;

    vector<li> dec = decomposite(M);
    li euc;
    euc = gdc_euclid(N, M);
    cout << euc << endl;

    li d = 1;
    for(auto it = dec.begin(); d < N && it != dec.end(); ++it) {
        d = d * (*it);
    }

    cout << d;
    return 0;
}