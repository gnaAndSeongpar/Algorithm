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

class MazeMaker {

public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {

        int dist[55][55];
        memset(dist, -1, sizeof(dist));

        queue<ii> q;
        q.push({startRow, startCol});
        dist[startRow][startCol] = 0;

        while (!q.empty()) {

            ii cur = q.front();
            q.pop();

            for (int i=0; i<moveRow.size(); i++) {
                int nx = cur.X+moveRow[i];
                int ny = cur.Y+moveCol[i];
                if (nx < 0 || nx >= maze.size() || ny < 0 || ny >= maze[0].size()) continue;
                if (maze[nx][ny] == 'X' || dist[nx][ny] != -1) continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
            }
        }

        int re = 0;
        for (int i=0; i<maze.size(); i++) {
            for (int j=0; j<maze[i].size(); j++) {
                if (maze[i][j] == 'X') continue;
                if (dist[i][j] == -1) return -1;
                re = max(re, dist[i][j]);
            }
        }
        return re;
    }
};


int main() {

    MazeMaker maker;
    cout<<maker.longestPath({"...", "...", "..."}, 0, 1, {1, 0, -1, 0}, {0, 1, 0, -1})<<endl;
    cout<<maker.longestPath({"...", "...", "..."}, 0, 1, {1, 0, -1, 0, 1, 1, -1, -1}, {0, 1, 0, -1, 1, -1, 1, -1})<<endl;
    cout<<maker.longestPath({"X.X", "...", "XXX", "X.X"}, 0, 1, {1, 0, -1, 0}, {0, 1, 0, -1})<<endl;
}