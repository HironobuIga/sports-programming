#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FriendScore {
    public:
    int highestScore(vector<string> friends) {
        int ans = 0;
        int n = friends[0].length();

        for(int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if(friends[i][j] == 'Y') {
                    count++;
                } else {
                    for(int k = 0; k < n; k++) {
                        if (friends[j][k] == 'Y' && friends[k][i] == 'Y') {
                            count++;
                            break;
                        }
                    }
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main(void) {
    vector<string> friends;
    int n;

    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        friends.push_back(s);
    }

    cout << FriendScore().highestScore(friends);
    return 0;
}