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

// 문제 풀기 전에
// Jim이 가는 모든 경로 확인하면서 가장 긴 길이 저장
// 모든 경우 확인 후 짐이 갈 수 없는 위치가 있는지 확인

bool visited[105][105];
int h[105][105];

class MazeMaker {

public:

    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol)    
    {
        memset(visited, false, sizeof(visited));
        memset(h, 0, sizeof(h));
        
        queue<ii> Q;
        Q.emplace(startRow, startCol);
        visited[startRow][startCol] = true;
        
        int ans = -1;
        while (!Q.empty()) // bfs로 이동 확인
        {
            ii curr = Q.front();
            Q.pop();
            
            for (int i = 0; i < moveRow.size(); i++)
            {
                ii next;
                next.xx = curr.xx + moveRow[i];
                next.yy = curr.yy + moveCol[i];
                
                if (next.xx < 0 || maze.size() <= next.xx) {
                    continue;
                }
                if (next.yy < 0 || maze[0].size() <= next.yy) {
                    continue;
                }
                if (visited[next.xx][next.yy]) {
                    continue;
                }
                if (maze[next.xx][next.yy] == 'X') {
                    continue;
                }
    
                visited[next.xx][next.yy] = true;
                
                h[next.xx][next.yy] = h[curr.xx][curr.yy] + 1;
                
                ans = max(ans, h[next.xx][next.yy]);
                Q.emplace(next.xx, next.yy);
            }
        }
        
        // 가지 못한 곳이 있는지 확인
        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[0].size(); j++) {
                if (maze[i][j] == 'X')
                    continue;
                
                if (!visited[i][j]) {
                    // cout << i << " " << j << endl;
                    return -1;
                }
            }
        }           
        
        return ans;
    }
};

int main() {

    MazeMaker mm;

    cout<<mm.longestPath({"...", "...", "..."}, 0, 1, {1, 0, -1, 0}, {0, 1, 0, -1})<<endl; // 3
    cout<<mm.longestPath({"...", "...", "..."}, 0, 1, {1, 0, -1, 0, 1, 1, -1, -1}, {0, 1, 0, -1, 1, -1, 1, -1})<<endl; // 2
    cout<<mm.longestPath({"X.X", "...", "XXX", "X.X"}, 0, 1, {1, 0, -1, 0}, {0, 1, 0, -1})<<endl; // -1
    cout<<mm.longestPath({".......", "X.X.X..", "XXX...X", "....X..", "X....X.", "......."}, 5, 0, {1, 0, -1, 0,-2, 1}, {0, -1, 0, 1, 3, 0})<<endl; // 7
    cout<<mm.longestPath({"......."}, 0, 0, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1})<<endl; // 6
    cout<<mm.longestPath({"..X.X.X.X.X.X."}, 0, 0, {2,0,-2,0}, {0,2,0,-2})<<endl; // -1
    return 0;
}