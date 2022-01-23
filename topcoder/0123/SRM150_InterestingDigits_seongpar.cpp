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


// (a * (n - 1) + b + 2 * a) * (n - 1) + (a + b + c)
//(a + b + c)가 n - 1의 배수라면 전체가 n - 1의 배수가 된다
// 10진수라면 9의 약수들이 해당됨

class InterestingDigits 
{
public:
	vector<int> digits(int base) {
		vector<int> ans;

		for (int i = 2; i * i < base; i++) {
			if (((base - 1) % i) == 0) {
				ans.push_back(i);
				ans.push_back((base - 1) / i);
			}
		}

		return ans;
	}
};