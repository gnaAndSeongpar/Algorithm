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

class CirclesCountry {


public:
    bool InCircle(int x, int y, int r, int a, int b) {
        return (x - a) * (x - a) + (y - b) * (y - b) < r * r;
    }

    int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {
        int ans = 0;

        for (int i = 0; i < X.size(); i++) {
            if (InCircle(X[i], Y[i], R[i], x1, y1) != InCircle(X[i], Y[i], R[i], x2, y2))
                ans++;
        }
        return ans;
    }
};

int main() {

    CirclesCountry cc;

    cout<<cc.leastBorders({0}, {0}, {2}, -5, 1, 5, 1)<<endl; // 0
    cout<<cc.leastBorders({0,-6,6}, {0,1,2}, {2,2,2}, -5, 1, 5, 1)<<endl; // 2
    cout<<cc.leastBorders({1,-3,2,5,-4,12,12}, {1,-1,2,5,5,1,1}, {8,1,2,1,1,1,2}, -5, 1, 12, 1)<<endl; // 3
    cout<<cc.leastBorders({-3,2,2,0,-4,12,12,12}, {-1,2,3,1,5,1,1,1}, {1,3,1,7,1,1,2,3}, 2, 3, 13, 2)<<endl; // 5
    cout<<cc.leastBorders({-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}, {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}, {135,42,70,39,89,39,43,150,10,120,16,8}, 102, 16, 19, -108)<<endl; // 3

    return 0;
}