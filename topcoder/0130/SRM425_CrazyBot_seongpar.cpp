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

bool visited[50][50];
int dx[] = { -1, 0, 1, 0 }; // 서 남 동 북
int dy[] = { 0, -1, 0, 1 };
double p[4];

class CrazyBot {

public:
double dfs(int x, int y, int n)
    {
        if (visited[x][y]) // 이미 갔다면 실패라 0
            return 0.0;
        if (n == 0) // n만큼 다 갔다면 성공이라 1
            return 1.0;
        
    
        visited[x][y] = true;
        double res = 0.0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            res += dfs(nx, ny, n - 1) * p[i];
        }
        visited[x][y] = false; // 확인 다 해서 false로
        
        return res;
    }

    double getProbability(int n, int east, int west, int south, int north) {
        p[0] = west / 100.0;
        p[1] = south / 100.0;
        p[2] = east / 100.0;
        p[3] = north / 100.0;
        
        memset(visited, false, sizeof(visited));    
        return dfs(25, 25, n);
    }
};

int main() {

    CrazyBot cb;

    cout<<cb.getProbability(1, 25, 25, 25, 25)<<endl; // 1.0
    cout<<cb.getProbability(2, 25, 25, 25, 25)<<endl; // 0.75
    cout<<cb.getProbability(7, 50, 0, 0, 50)<<endl; // 1.0
    cout<<cb.getProbability(14, 50, 50, 0, 0)<<endl; // 2/2^14
    cout<<cb.getProbability(14, 25, 25, 25, 25)<<endl; // 작은 확률
}