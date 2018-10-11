#include <iostream>
#include <algorithm>

using namespace std;

#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li N;
    cin >> N;
    li x[N], y[N], h[N];
    FOR(i, 0, N) {
        cin >> x[i] >> y[i] >> h[i];
    }

    FOR(cx, 0, 101) {
        FOR(cy, 0, 101) {
            li criteria = -1;
            bool isAnswer = true;
            FOR(i, 0, N) {
                if (h[i] != 0) {
                    criteria = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                }
            }
            FOR(i, 0, N) {
                if (h[i] == 0) { 
                    if (criteria - abs(cx - x[i]) - abs(cy - y[i]) > 0) {
                        isAnswer = false;
                        break;
                    }
                    continue;
                 }
                li H = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                if (criteria != H) { 
                    isAnswer = false;
                    break;
                }
            }
            if (isAnswer) {
                cout << cx << " " << cy << " " << criteria << endl;
                return 0;
            }
        }
    }

    return 0;
}
