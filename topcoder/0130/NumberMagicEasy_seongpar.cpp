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

class NumberMagicEasy {

public:

    int theNumber(string answer)
    {
        vector<string> v = {
            "YYYY", 
            "YYYN",
            "YYNY",
            "YYNN",
            "YNYY",
            "YNYN",
            "YNNY",
            "YNNN",
            "NYYY",
            "NYYN",
            "NYNY",
            "NYNN",
            "NNYY",
            "NNYN",
            "NNNY",
            "NNNN"
        };

        for (int i = 0; i < v.size(); i++) {
            if (answer == v[i])
                return i + 1;
        }
        return 0;
    }
};