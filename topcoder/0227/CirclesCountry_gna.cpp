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


class CirclesCountry {

public:
    int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2) {

        int cnt = 0;
        int sz = X.size();
        for (int i=0; i<sz; i++) {
            int a = X[i], b = Y[i], r = R[i];
            bool eq1 = ((x1-a)*(x1-a)+(y1-b)*(y1-b) < r*r);
            bool eq2 = ((x2-a)*(x2-a)+(y2-b)*(y2-b) < r*r);
            if (eq1 != eq2) cnt++;
        }
        return cnt;
    }
};

int main() {

    CirclesCountry cir;
    cout<<cir.leastBorders({0}, {0}, {2}, -5, 1, 5, 1)<<endl; //0
    cout<<cir.leastBorders({0, -6, -6}, {0, 1, 2}, {2, 2, 2}, -5, 1, 5, 1)<<endl; // 2;
    cout<<cir.leastBorders({1, -3, 2, 5, -4, 12, 12}, {1, -1, 2, 5, 5, 1, 1}, {8, 1, 2, 1, 1, 1, 2}, -5, 1, 12, 1)<<endl; //3
    cout<<cir.leastBorders({-3, 2, 2, 0, -4, 12, 12, 12}, {-1, 2, 3, 1, 5, 1, 1, 1}, {1, 3, 1, 7, 1, 1, 2, 3}, 2, 3, 13, 2)<<endl; //5
    cout<<cir.leastBorders(
        {-107, -38, 140, 148, -198, 172, -179, 148, 176, 153, -56, -187},
        {175, -115, 23, -2, -49, -151, -52, 42, 0, 68, 109, -174}, 
        {135, 42, 70, 39, 89, 39, 43, 150, 10, 120, 16, 8}, 102, 16, 19, -108); //3
 }