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

class HamiltonPath {
    vector<int> parent;

    void    init(int n)
    {
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int     find(int x)
    {
        if (x == parent[x])
            return x;
        return (parent[x] = find(parent[x]));
    }

    void    merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        parent[x] = y;
    }

public:
    // Y가 3개 이상인지 확인
    bool isYmoreThan3(vector <string> &roads) {
        for (int i = 0; i < roads.size(); i++) {
            int count = 0;

            for (int j = 0; j < roads[i].size(); j++) {
                if (roads[i][j] == 'Y')
                    count++;
            }

            if (count >= 3)
                return true;
        }
        return false;
    }

    i64 factorial(i64 n) {
        i64 res = 1;

        for (int i = n; i > 0; i--)
            res *= i;
        return res;
    }

    int countPaths(vector <string> roads) {
        init(roads.size());

        if (isYmoreThan3(roads))
            return 0;

        for (int i = 0; i < roads.size(); i++) {
            for (int j = 0; j < roads[i].size(); j++) {
                if (i >= j)
                    continue;
                
                if (roads[i][j] == 'N')
                    continue;

                if (find(i+1) == find(j+1)) // 순환하는 경우 1 -> 2 -> 0 -> 1
                    return 0;

                merge(i+1, j+1);
            }
        }

        vector<int> count(roads.size()+1);
        for (int i = 1; i <= count.size(); i++) {
            count[find(i)]++;
        }

        i64 C = 0; // 반드시 거쳐야 하는 경로가 C개
        i64 I = 0; // 자유롭게 지나갈 수 있는 도시가 I개
        for (int i = 1; i <= count.size(); i++) {
            if (count[i] == 1)
                I++;
            else if (count[i] > 1)
                C++;
        }

        return factorial(C + I) * 2 * C % 1000000007;
    }
};

int main() {

    HamiltonPath hp;

    cout<<hp.countPaths({"NYN", "YNN", "NNN"})<<endl; // 4
    cout<<hp.countPaths({"NYYY", "YNNN", "YNNN", "YNNN"})<<endl; // 0
    cout<<hp.countPaths({"NYY", "YNY", "YYN"})<<endl; // 0
    cout<<hp.countPaths({"NNNNNY", "NNNNYN", "NNNNYN", "NNNNNN", "NYYNNN", "YNNNNN"})<<endl; // 24

    return 0;
}