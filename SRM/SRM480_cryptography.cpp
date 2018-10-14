#include <iostream>
#include <vector>

using namespace std;

class Cryptography {
    public:
     long long encrypt(vector <int> numbers) {
        long long ans = 0;

        for (int i = 0 ; i < numbers.size(); i++) {
            long long seki = 1;
            for (int j = 0; j < numbers.size(); j++) {
                if ( i == j) {
                    seki *= (numbers[j] + 1);
                } else {
                    seki *= numbers[j];
                }
            }
            ans = max(ans, seki);
        }
        return ans;
    }

};

int main() {
    int N;
    cin >> N;
    vector <int> nums;
    for (int i = 0; i < N ; i++) {
        int number;
        cin >> number;
        nums.push_back(number);
    }

    long long ans = 0;
    ans = Cryptography().encrypt(nums);

    cout << ans;
    return 0;
}