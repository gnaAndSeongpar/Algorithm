#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


class CrazyBot {

public:

    int N;
    double re;
    double p[4];
    bool visited[1000][1000] = {};

    void dfs(int x, int y, int k, double prob) {
        
        if (k == N) {
            re += prob;
            return ;
        }

        visited[x][y] = true;
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (visited[nx][ny]) continue;
            dfs(nx, ny, k+1, prob*p[i]);
            visited[nx][ny] = false;
        }
    }

    double getProbability(int n, int east, int west, int south, int north) {

        N = n;
        re = 0;
        memset(visited, false, sizeof(visited));

        p[0] = east/100.0;
        p[1] = west/100.0;
        p[2] = south/100.0;
        p[3] = north/100.0;

        dfs(500, 500, 0, 1);
        return re;
    }   
};


int main() {

    CrazyBot bot;
    cout<<bot.getProbability(1, 25, 25, 25, 25)<<endl;
    cout<<bot.getProbability(2, 25, 25, 25, 25)<<endl;
    cout<<bot.getProbability(7, 50, 0, 0, 50)<<endl;
}