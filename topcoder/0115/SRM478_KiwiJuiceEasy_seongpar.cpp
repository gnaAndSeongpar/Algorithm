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


class KiwiJuiceEasy {

public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {

        
        for (int i = 0; i < fromId.size(); i++) {
            int f = fromId[i];
            int t = idId[i];

            int vol = min(bottles[f], capacities[t] - bottles[t]);

            bottles[f] -= vol;
            bottles[t] += vol;
        }

        return bottles;
    }
};
