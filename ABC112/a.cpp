#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

int main(void) {
    li N;
    cin >> N;

    if (N == 1) {
        cout << "Hello World";
        return 0;
    } else {
        li A, B;
        cin >> A >> B;
        cout << A + B;
        return 0;
    }
}