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

// union find 

class FriendScore {

public:

    int highestScore(vector<string> friends) {

        int re = 0;
        for (int i=0; i<friends.size(); i++) { //i번째 사람의 친구 찾기

            bool visited[55];
            memset(visited, false, sizeof(visited));
            visited[i] = true;

            int cnt = 0;
            for (int j=0; j<friends[i].size(); j++) {
                if (friends[i][j] == 'N') continue;
                if (visited[j]) continue;
                cnt++;
                visited[j] = true;

                for (int k=0; k<friends[j].size(); k++) {
                    if (friends[j][k] == 'N') continue;
                    if (visited[k]) continue;
                    cnt++;
                    visited[k] = true;
                }
            }
            re = max(cnt, re);
        }
        return re;
    }
};

int main() {

    FriendScore fr;

    vector<string> f1 = {"NNN", "NNN", "NNN"};
    vector<string> f2 = {"NYY", "YNY", "YYN"};
    vector<string> f3 = {"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"};

    cout<<fr.highestScore(f1)<<endl; // 0
    cout<<fr.highestScore(f2)<<endl; // 2
    cout<<fr.highestScore(f3)<<endl; // 4
}