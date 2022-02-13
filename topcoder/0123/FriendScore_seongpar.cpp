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

class FriendScore {
public: 
	int highestScore(vector<string> friends) {
		int ans = 0;
		int n = friends[0].size();

		// 전체 n 명 일일히 확인
		for (int i = 0; i < n; i++) {
			int cnt = 0;

			// i와 j가 친구인가요????
			for (int j = 0; j < n; j++) {
				// 본인은 패스
				if (i == j)
					continue;

				// 확실한 친구라면 cnt++
				if (friends[i][j] == 'Y') {
					cnt++;
					continue;
				}

				// j - k - i 이런 관계가 있는지 확인
				for (int k = 0; k < n; k++) {
					if (friends[j][k] == 'Y' && friends[k][i] == 'Y') {
						cnt++;
						break;
					}
				}
			}
		}
		ans = max(ans, cnt);
	}

	return ans;
};