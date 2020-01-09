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
    string s;
    li K;
    cin >> s >> K;
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j', 'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    li count = K;

    FOR(i, 0, s.length()) {
        li index = 0;
        FOR(j, 0, 26) {
            // s[i]がa~zで何文字目か探す
            if (letters[j] == s[i]) {
                index = j;
                break;
            }
        } 
        li add = 26 - index; // 一巡するために足さなければいけない回数
        if (count >= add) {
            count = count - add;
            s[i] = 'a'; // i番目の要素をaに書き換え
        }

        if (count > 0 && (i == s.length() - 1)) {
            // 最後まで行き、操作回数が余っている場合
            li lastIndex = 0;
             FOR(j, 0, 26) {
                // s[i]がa~zで何文字目か探す
                if (letters[j] == s[i]) {
                    index = j;
                    break;
                }
            }
            

            li left = count % 26; // 英語の巡回のあまりを出す
        }
    }

    return 0;
}
