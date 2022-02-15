#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

i64 mapv[150][150][100];
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2, 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1, 0, 1, 1, 1, 0, -1, -1, -1 };

class ChessMetric {
    int size;
    vector <int> end;

public:
    i64 dp(int x, int y, int numMoves) {
        auto& res = mapv[x][y][numMoves];
        
        if (res != -1) // 이미 계산된 값이라면 바로 리턴
            return res;
        if (x == end[0] && y == end[1] && numMoves == 0) // 도착했다면
            return res = 1;
        
        i64 sum = 0;
        for (int i = 0; i < 16; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nMove = numMoves - 1;

            if (nx < 0 || size <= nx || ny < 0 || size <= ny || nMove < 0)
                continue;

            sum += dp(nx, ny, nMove);
        }
        
        return res = sum;
    }


    i64 howMany(int _size, vector <int> start, vector <int> _end, int _numMoves) {
        memset(mapv, -1, sizeof(mapv));
        size = _size;
        end = _end;

        i64 ans = dp(start[0], start[1], _numMoves);
        
        return ans;
    }
};

int main() {

    ChessMetric cm;

    cout<<cm.howMany(3, {0,0}, {1,0}, 1)<<endl; // 1
    cout<<cm.howMany(3, {0,0}, {1,2}, 1)<<endl; // 1
    cout<<cm.howMany(3, {0,0}, {2,2}, 1)<<endl; // 0
    cout<<cm.howMany(3, {0,0}, {0,0}, 2)<<endl; // 5
    cout<<cm.howMany(100, {0,0}, {0,99}, 50)<<endl; // 243097320072600

    return 0;
}