#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;
#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

li gcd(li a,li b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int main(void) {
    string S;
    cin >> S;
    li n = S.length();

    li nums[10];
    FOR(i, 0, n) {
        char temp = S[i];
        nums[i] = temp - '0'; // 文字コードを数字にする
    }

    li ans = 999; // 大きい数
    FOR(i, 0, n - 2) {
        li num = nums[i] * 100 + nums[i + 1] * 10 + nums[i + 2];
        li diff = abs(num - 753);
        if (diff < ans) {
            ans = diff;
        }
    }
    cout << ans;
    return 0;
}