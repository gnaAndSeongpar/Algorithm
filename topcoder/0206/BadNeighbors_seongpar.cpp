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

class BadNeighbors {

public:
    int maxDonations (vector<int> donations) {
        int i;
        int ans = 0;
        int N = donations.size();
        int *dp = new int [N];

        for (i = 0; i < N-1; i++) {
            dp[i] = donations[i];
            if (i > 0)
                dp[i] = max(dp[i], dp[i-1]);
            if (i > 1)
                dp[i] = max(dp[i], dp[i-2] + donations[i]);
            ans = max(ans, dp[i]);
        }

        for (i = 0; i < N-1; i++) {
            dp[i] = donations[i+1];
            if (i > 0)
                dp[i] = max(dp[i], dp[i-1]);
            if (i > 1)
                dp[i] = max(dp[i], dp[i-2] + donations[i+1]);
            ans = max(ans, dp[i]);
        }

        delete [] dp;
        return ans;
    }
};

int main() {
    BadNeighbors bn;

    cout<<bn.maxDonations({ 10, 3, 2, 5, 7, 8 })<<endl; // 19
    cout<<bn.maxDonations({ 11, 15 })<<endl; // 15
    cout<<bn.maxDonations({ 7, 7, 7, 7, 7, 7, 7 })<<endl; // 21
    cout<<bn.maxDonations({ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 })<<endl; // 16
    cout<<bn.maxDonations({ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 })<<endl; // 2926

    return 0;
}