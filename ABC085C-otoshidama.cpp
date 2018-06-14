#include <iostream>
 
using namespace std;
 
int main(void) {
    int N;
    cin >> N;
 
    int Y;
    cin >> Y;
 
    int answer[3];
    answer[0] = -1;
    answer[1] = -1;
    answer[2] = -1;
 
    for (int yukichi = 0; yukichi <= N ; yukichi++) {
        for (int noguchi = 0; noguchi <= N - yukichi; noguchi++) {
            int total = 0;
            total = yukichi *  10000 + noguchi * 5000 + (N - yukichi - noguchi) * 1000;
                if (total == Y) {
                    answer[0] = yukichi;
                    answer[1] = noguchi;
                    answer[2] = N - yukichi - noguchi;
                }
        }
    }
    cout << answer[0];
    cout << " ";
    cout << answer[1];
    cout << " ";
    cout << answer[2]; 
    
    return 0;
}