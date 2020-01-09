#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li sum[100100];
    REP(i, 100100) { sum[i] = 0; }
    
    li Q;
    cin >> Q;
    li l[Q + 100];
    li r[Q + 100];
    FOR(i, 0, Q) { cin >> l[i] >> r[i]; }

    vector<li> primeNumber; // 素数配列
    primeNumber.push_back(2);
    FOR(i, 2, 100100) {
        bool isPrimeNumber = true;
        FOR(k, 0, primeNumber.size()) {
            if ((i % primeNumber[k]) == 0) {
                // 今まで見つかった素数で割り切れた場合は素数ではない
                isPrimeNumber = false;
                break;
            }
        }
        if (isPrimeNumber) {
            // 今までの素数で割り切れなければ素数であるため素数配列に追加する
            primeNumber.push_back(i);
        }
    }
    
    // 先に累積和をすべて出し、その累積和の差分で各個数を求める
    FOR(i, 1, 100100) {
        sum[i] = sum[i - 1];
        bool found = find(primeNumber.begin(), primeNumber.end(), i) != primeNumber.end();
        if (!found) { continue; } // iが素数でなければ飛ばす

        bool found_second = find(primeNumber.begin(), primeNumber.end(), (i+1)/2) != primeNumber.end();
        if (found_second) { sum[i] += 1; }
    } 

    FOR(i, 0 , Q) { cout << sum[r[i]] - sum[l[i] - 1] << endl; }
    return 0;
}
