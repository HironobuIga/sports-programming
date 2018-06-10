#include <iostream>
using namespace std;

int main(void) {
    int numberOf500;
    cin >> numberOf500;
    int numberOf100;
    cin >> numberOf100;
    int numberOf50;
    cin >> numberOf50;
    int Total;
    cin >> Total;

    int answer = 0;
    for (int count500 = 0; count500 <= numberOf500; count500++) {
        for (int count100 = 0; count100 <= numberOf100; count100++) {
            for (int count50 = 0; count50 <= numberOf50; count50++) {
                if (500*count500 + 100 * count100 + 50 * count50 == Total) {
                    answer = answer + 1;
                }
            }
        }
    }

    cout << answer;

    return 0;
}