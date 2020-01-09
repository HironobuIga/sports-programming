#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector <int> d;
    for (int i = 0 ; i < N ; i++) {
        int diametor;
        cin >> diametor;
        d.push_back(diametor);
    }

    sort(d.begin(), d.end());

    int count;
    d.erase(unique(d.begin(), d.end()), d.end());
    count = d.size();

    cout << count;
    return 0;
}