#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

int main(void) {
    li a, b;
    cin >> a >> b;
    li s = (a - 1) * (b - 1);
    cout << s;
    return 0;
}