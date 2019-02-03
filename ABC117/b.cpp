#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <math.h>
#include <map>

using namespace std;
#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

// ユークリッドの互除法
li gcd(li a,li b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

// 素数判定
bool isPrime(li n) {
    for(li i = 0; i * i < n ; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // 1は例外
}

// 素因数分解
map<li, li> prime_factor(li n) {
    map<li, li> res;
    FOR(i, 0, sqrt(n)) {
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}
 
int main(void) {
    li N;
    cin >> N;
    li L[N];
    FOR(i, 0, N) {
        li tempL;
        cin >> tempL;
        L[i] = tempL;
    }

    li max = 0, maxIndex = 0, sumMinusMax = 0;
    FOR(i, 0, N) {
        sumMinusMax += L[i];
        if (max < L[i]) {
            max = L[i];
            maxIndex = i;
        }
    }

    li sum;
    sumMinusMax = sumMinusMax - max;
    
    if (max < sumMinusMax) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl; 
    }

    return 0;
}
