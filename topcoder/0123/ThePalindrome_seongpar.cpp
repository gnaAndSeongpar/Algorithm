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

class ThePalindrom {
public: 
	int find(string s) {
		// 답 문자 길이 정하기
		// 전체 문자 길이에서 1씩 증가함
		for (int i = s.size(); ; i++) {
			bool flag = true;

			// 0부터 문자열 길이까지 확인
			for (int j = 0; j < s.size(); j++) {
				// (i - j - 1) : 뒤에서부터 접근
				// 문자열 밖의 인덱스를 접근할 수 있나???
				// 문자열 밖을 넘지 않는 범위를 확인하는데 두 문자가 다르면 패스 -> 다음거 확인
				if ((i - j - 1) < s.size() && s[j] != s[i - j - 1]) {
					flag = false;
					break;
				}
			}

			// 조건 모두 만족시 답을 반환
			if (flag)
				return i;
		}
	}
};