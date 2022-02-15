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

int dp[50][2][2]; //dp[i][j][k]: i번째 집까지의 최대 기부금(j: i번째 집의 수금 여부, k: 0번째 집의 수금 여부)

class BadNeighbors {

public:
    int maxDonations(vector<int> donations) {

        int N = donations.size();
        
        dp[0][1][1] = donations[0];
        dp[1][0][1] = donations[0];
        dp[1][1][0] = donations[1];

        for (int i=2; i<N; i++) {
            dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]);
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1]);
            dp[i][1][0] = donations[i] + dp[i-1][0][0];
            dp[i][1][1] = donations[i] + dp[i-1][0][1];
        }

        return max({dp[N-1][0][0], dp[N-1][0][1], dp[N-1][1][0]});
    }
};

int main() {

    BadNeighbors neighbor;
    cout<<neighbor.maxDonations({10, 3, 2, 5, 7, 8})<<endl; //19
    cout<<neighbor.maxDonations({11, 15})<<endl; //15
    cout<<neighbor.maxDonations({7, 7, 7, 7, 7, 7, 7})<<endl; //21
    cout<<neighbor.maxDonations({1, 2, 3, 4, 5, 1, 2, 3, 4, 5})<<endl; //16
    cout<<neighbor.maxDonations({ //2926
        94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 
        12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 
        435, 7, 36, 57, 86, 81, 72})<<endl;
    return 0;
}