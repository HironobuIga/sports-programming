#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InterestingParty {
    public:
    int bestInvitation(vector <string> first, vector <string> second) {
        int i, j;
        int ans = 0;

        for (i = 0; i < first.size(); i++) {
            int f = 0;
            int s = 0;

            for (j = 0; j < second.size(); j++)  {
                if (first[i] == first[j]) f++;
                if (first[i] == second[j]) f++;
                if (second[i] == second[j]) s++;
                if (second[i] == first[j]) s++;
            }

            ans = max(f, ans);
            ans = max(s, ans);
        }

        return ans;
    }
};

int main(void) {
    int N;
    cin >> N;
    vector <string> first;
    vector <string> second;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        first.push_back(input);
    }
    for (int j = 0; j < N; j++) {
        string input;
        cin >> input;
        second.push_back(input);
    }
    
    int ans;
    ans = InterestingParty().bestInvitation(first, second);
    cout << ans;

    return 0;
}