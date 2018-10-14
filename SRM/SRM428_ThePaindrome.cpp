#include <iostream>
#include <vector>

using namespace std;

class ThePalindrome {
    public:
    int find(string s) {
        for(int i = s.size() ; ; i++) {

            bool flag = true;
            for(int j = 0; j < s.size(); j++) {
                //反対側の文字が存在　かつ 異なる場合は回文ではない
                if (i - j - 1 < s.size() && s[j] != s[i - j - 1]) {
                    flag = false;
                    break;
                }
            }

            if (flag) return i;
        }
    }
};

int main(void) {
    string s;
    cin >> s;
    cout << ThePalindrome().find(s);
    return 0;
}