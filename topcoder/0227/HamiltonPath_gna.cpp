#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;


class HamiltonPath {

public:
    vector<string> roads;
    int group, indiv, sz;

    void dfs(vector<bool>&visited, int node) {
        
        visited[node] = true;
        for (int i=0; i<sz; i++) {
            if (roads[node][i] == 'Y' && !visited[i]) dfs(visited, i);
        }
    }

    int countPaths(vector<string> roads) {
        
        vector<int> nconnected(50, 0);
        vector<bool> visited(50, false);
        
        this->roads = roads;
        group = 0, indiv = 0, sz = roads.size();

        // 각 노드에 연결된 노드의 개수 구하기
        for (int i=0; i<sz; i++) { 
            int cnt = 0;
            for (int j=0; j<sz; j++) {
                if (roads[i][j] =='Y') cnt++;
            }
            // 노드에 3개 이상의 노드가 연결되어있으면 0 리턴
            if (cnt > 2) return 0; 
            nconnected[i] = cnt;
        }

        for (int i=0; i<sz; i++) {
            // 연결된 노드가 없을 경우 개별 노드로 취급
            if (!nconnected[i]) { 
                visited[i] = true;
                indiv++;
            }
            // 연결노드가 1개인 경우 그룹의 시작점이 될 수 있으므로 dfs 수행
            else if (nconnected[i] == 1 && !visited[i]) { 
                group++;
                dfs(visited, i);
            }
        }

        // 모든 노드를 순회했음에도 아직 방문하지 않은 노드가 있는 경우 0 리턴
        for (int i=0; i<sz; i++) { 
            if (!visited[i]) return 0;
        }


        // (C+I)!*2C
        long long sum = 1;
        for (int i=0; i<group+indiv; i++)
            sum = sum * (i+1) % 100000007;
        for (int i=0; i<group; i++) 
            sum = sum*2 % 1000000007;
        return (int)sum;
    }
};

int main() {

    HamiltonPath path;
    cout<<path.countPaths({"NYN", "YNN", "NNN"})<<endl;
    cout<<path.countPaths({"NYYY", "YNNN", "YNNN", "YNNN"})<<endl;
    cout<<path.countPaths({"NNNNNY", "NNNNYN", "NNNNYN", "NNNNNN", "NYYNNN", "YNNNNN"})<<endl;
}