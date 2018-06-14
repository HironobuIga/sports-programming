#include <iostream>
#include <vector>
using namespace std;

class KiwiJuiceEasy {
    public: 
    vector <int> thePouring(vector <int> capacities,
    vector <int> bottles,
    vector <int> fromId, vector <int> toId) {
        for (int index = 0; index < fromId.size(); index++) {
            int from = fromId[index];
            int to = toId[index];
            int space = capacities[to] - bottles[to];

            int vol = min(space, bottles[from])
            bottles[to] = bottles[to] + vol;
            bottles[from] = bottles[from] - vol;
        }
        return bottles;
    }
};