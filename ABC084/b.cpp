#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    string answer = "Yes";
    if ( S[A] != '-' ) {
        // 仕様を満たさず、 A+1文字目が-でなければ不可
        answer = "No";
    } else {
        FOR(index, 0, S.size()) {
            if (index == A) {
                continue;
            }
            if (S[index] == '-') {
                // A+1文字目以外に - が含まれている場合は不可
                answer = "No";
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}
