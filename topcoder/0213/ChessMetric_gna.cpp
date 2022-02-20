#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


int dx[16] = {-1, -1, -1, 0, 0, 1, 1, 1, -2, -1, -2,-1, 1, 2, 1, 2};
int dy[16] = {-1, 0, 1, -1, 1, -1, 0, 1, -1, -2, 1, 2, -2, -1, 2, 1};

long long dp[105][105][55]; 

class ChessMetric {

public:

    long long howMany(int size, vector<int> start, vector<int> end, int numMoves) {

        memset(dp, 0, sizeof(dp));

        int sx = start[0], sy = start[1], ex = end[0], ey = end[1];

        dp[sx][sy][0] = 1;
        for (int i=1; i<=numMoves; i++) {
            for (int x=0; x<size; x++) {
                for (int y=0; y<size; y++) {
                    for (int j=0; j<16; j++) {
                        int nx = x+dx[j];
                        int ny = y+dy[j];
                        if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                        dp[nx][ny][i] += dp[x][y][i-1];
                    }
                }
            }
        }
        return dp[ex][ey][numMoves];
    }
};

int main() {

    ChessMetric chess;
    cout<<chess.howMany(3, {0, 0}, {1, 0}, 1)<<endl; //1
    cout<<chess.howMany(3, {0, 0}, {1, 2}, 1)<<endl; //1
    cout<<chess.howMany(3, {0, 0}, {2, 2}, 1)<<endl; //0
    cout<<chess.howMany(3, {0, 0}, {0, 0}, 2)<<endl; //5
    cout<<chess.howMany(100, {0, 0}, {0, 99}, 50)<<endl; //243097320072600
}


// 단순 dfs는 제한 시간 내에 통과 X
/*
class ChessMetric {

    int sz;
    int stx, sty;
    int enx, eny;
    int nMoves;
    long long re;

public:

    void dfs(int x, int y, int num) {

        if (num == nMoves) {
            if (x == enx && y == eny) re++;
            return ;
        }

        for (int i=0; i<16; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) continue;
            dfs(nx, ny, num+1);
        }
    }

    long long howMany(int size, vector<int> start, vector<int> end, int numMoves) {

        stx = start[0]; sty = start[1];
        enx = end[0]; eny = end[1];
        sz = size; nMoves = numMoves;
        re = 0;
        
        dfs(stx, sty, 0);
        return re;
    }
}; 
*/