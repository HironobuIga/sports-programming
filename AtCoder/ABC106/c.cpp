#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    string s;
    li K;
    cin >> s >> K;
    li ans;

    REP(i, min((li)s.size(), K)) {
        if (s[i] >= '2') {
            cout << s[i] << endl;
            return 0;
        }
    } 

    cout << '1' << endl;
    return 0;
}