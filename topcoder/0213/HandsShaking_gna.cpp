#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


//dp[i]: 2*i의 원에서 교차없이 악수하는 경우의 수
//카탈랑수

class HandShaking {

    long dp[50];

public: 
    long countPerfect(int n) {

        memset(dp, 0, sizeof(dp));

        dp[0] = 1; dp[1] = 1;
        for (int i=2; i<=n/2; i++) {
            for (int j=0; j<i; j++)
                dp[i] += dp[j]*dp[i-1-j];
        }
        return dp[n/2];
    }
};

int main() {

    HandShaking hand;
    cout<<hand.countPerfect(2)<<endl;
    cout<<hand.countPerfect(4)<<endl;
    cout<<hand.countPerfect(6)<<endl;
    cout<<hand.countPerfect(8)<<endl;
}