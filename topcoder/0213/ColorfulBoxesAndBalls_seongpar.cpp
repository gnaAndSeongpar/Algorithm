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
#include <climits>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

class ColorfulBoxesAndBalls {

public:

     int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
        int change = min(numRed, numBlue);

        int maxv = INT_MIN;
        for (int i = 0; i <= change; i++) {
            maxv = max(onlyRed * (numRed - i) + onlyBlue * (numBlue - i) + 2 * bothColors * i, maxv);
        }

        return maxv;
    }
};

int main() {

    ColorfulBoxesAndBalls cbab;

    cout<<cbab.getMaximum(2, 3, 100, 400, 200)<<endl; // 1400
    cout<<cbab.getMaximum(2, 3, 100, 400, 300)<<endl; // 1600
    cout<<cbab.getMaximum(5, 5, 464, 464, 464)<<endl; // 4640
    cout<<cbab.getMaximum(1, 4, 20, -30, -10)<<endl; // -100
    cout<<cbab.getMaximum(9, 1, -1, -10, 4)<<endl; // 0
}