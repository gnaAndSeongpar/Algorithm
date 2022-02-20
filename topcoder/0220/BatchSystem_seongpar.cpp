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


    
class BatchSystem {

public:
    static bool cmp( pair<string, ii> a, pair<string, ii> b) {
        if (a.yy.xx == b.yy.xx) {
            return a.yy.yy < b.yy.yy;
        }
        return a.yy.xx < b.yy.xx;
    }

    vector<int> schedule(vector <int> duration, vector <string> user) {
        // 사용자와 순번을 map으로 저장한다
        map<string, vector<int>> sequence;
        for (int i = 0; i < user.size(); i++) {
            sequence[user[i]].push_back(i);
        }


        // 사용자와 걸린 시간을 map에 저장
        map<string, int> time;
        for (int i = 0; i < user.size(); i++) {
            time[user[i]] += duration[i];
        }
        
        
        // 걸린 시간을 오름차순으로 정렬한다
        vector<pair<string, int>> v(all(time));
        vector<pair<string, ii>> convertV(v.size());
        for (int i = 0; i < v.size(); i++) {
            convertV[i].xx = v[i].xx;
            convertV[i].yy.xx = v[i].yy;
            convertV[i].yy.yy = sequence[v[i].xx][0];
        }
        sort(all(convertV), cmp);
        
        
        // 앞에서부터 사용자 순번을 저장한다
        vector<int> ans;
        for (auto pp : convertV) {
            string name = pp.xx;
            vector<int> userSequence = sequence[name];
            for (int i = 0; i < userSequence.size(); i++) {
                ans.push_back(userSequence[i]);
            }
        }

        return ans;
    }
};

void printVector(vector<int> v) {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }

int main() {

    BatchSystem bs;

    printVector(bs.schedule({400, 100, 100, 100}, {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"})); //  {3, 1, 2, 0 }
    printVector(bs.schedule({200, 200, 200}, {"Gil", "Sarah", "Warrick"})); //  {0, 1, 2 }
    printVector(bs.schedule({100, 200, 50}, {"Horatio Caine", "horatio caine", "YEAAAAAAH"})); // {2, 0, 1 }
    printVector(bs.schedule({300, 200, 100, 100}, {"a", "c", "b", "b"}));

    return 0;
}