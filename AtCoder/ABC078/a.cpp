#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)
 
int main(void) {
    string X, Y;
    cin >> X >> Y;
    if (X > Y) {
        cout << ">";
    } else if (X < Y) {
        cout << "<"; 
    } else {
        cout << "=";
    }
    return 0;
}