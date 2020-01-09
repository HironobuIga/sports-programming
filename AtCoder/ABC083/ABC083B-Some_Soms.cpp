#include <iostream>
using namespace std;

int main(void) {
    int lower, upper, N;
    cin >> N >> lower >> upper;

    int answerCount = 0;
    for (int number = 1; number <= N; number++) {
        int total = 0;
        int  div = number;
        while  (div != 0) {
            total = total + div % 10;
            div = div / 10;
        }
        if (total >= lower && total <= upper) {
            answerCount = answerCount + number;
        }
    }

    cout << answerCount;
    return 0;
}