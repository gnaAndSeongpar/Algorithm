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

class InterestingParty {

public:
    int bestInvitation(vector<string> first, vector<string> second) {

        map<string, int> m;

        for (int i = 0; i < first.size(); i++) {
            m[first[i]]++;
            m[second[i]]++;
        }

        int ans = -1;
        for (auto& [key, value]: m)
            ans = max(value, ans);
    }

    return ans;
};
