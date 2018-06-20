#include <iostream>
#include <vector>

using namespace std;

class InterestingDigits {
    public:
    vector <int> digits(int base) {
        vector <int> answers;
        for (int n = 2; n < base; n++) {
            bool ok = true;
            for (int j1 = 0; j1 < base; j1++) {
                for (int j2 = 0; j2 < base; j2++) {
                    for (int j3 = 0; j3 < base; j3++) {
                        if ((j1 + j2 * base + j3 *base * base ) % n == 0 &&
                            (j1 + j2 + j3) %n != 0) {
                                ok = false;
                                break;
                            }
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (!ok) {
                    break;
                }
            }
            if (ok) {
                answers.push_back(n);
            }
        }
        return answers;
    }
};

int main(void) {
    int N;
    cin >> N;
    vector <int> answer = InterestingDigits().digits(N);
    return 0;
}