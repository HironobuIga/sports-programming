#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;
#define li long long int
#define FOR(i, a, b) for (int i = a ; i < b ; ++i)
#define REP(i, n) for (int i = 0 ; i < n ; ++i)

li gcd(li a,li b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int main(void) {
    li x, y;
    cin >> x >> y;
    
    li absX = abs(x);
    li absY = abs(y);
    
    // yに比較したxの初期座標がどの位置かで行動が決まる
    // xとyは異なるためすべてのパターンは8通り
    
    // 同じ符号
    if (x > 0 && y > 0 && absX > absY) {
        // ともに正
        cout << (absX - absY) + 2;
        
    } else if (x > 0 && y > 0 && absX < absY) {
        // ともに正
        cout << absY - absX;
    } else if (x < 0 && y < 0 && absX > absY) {
        // ともに負
        cout << absX - absY;
    } else if (x < 0 && y < 0 && absX < absY) {
        // ともに負
        cout << (absY - absX) + 2;
    }
    // 異なる符号
    // 符号が異なる場合は一度反転がいる
    if (x > 0 && y < 0 && absX >= absY) {
        // x正 y負
        cout << (absX - absY) + 1;
    } else if (x > 0 && y < 0 && absX <= absY) {
        // x正 y負
        cout << (absY - absX) + 1;
    } else if (x < 0 && y > 0 && absX >= absY) {
        // x負 y正
        cout << (absX - absY) + 1;
    } else if (x < 0 && y > 0 && absX <= absY) {
        // x負 y正
        cout << (absY - absX) + 1;
    }
    
    // y = 0パターン
    if (y == 0) {
        if (x > 0) {
            cout << absX + 1;
        } else {
            cout << absX;
        }
    }
    
    // x = 0パターン
    if (x == 0) {
        if (y > 0) {
            cout << absY;
        } else {
            cout << absY + 1;
        }
    }
    
    cout << endl;
    return 0;
}
