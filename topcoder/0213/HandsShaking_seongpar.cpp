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

class HandsShaking {

public:

    i64 countPerfect(int n) {
        vector<i64> dp(n / 2 + 1);

        dp[0] = 1;

        for (int i = 1; i <= n / 2; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n / 2];
    }
};

int main() {

    HandsShaking hs;

    cout<<hs.countPerfect(2)<<endl; // 1
    cout<<hs.countPerfect(4)<<endl; // 2
    cout<<hs.countPerfect(8)<<endl; // 14
}