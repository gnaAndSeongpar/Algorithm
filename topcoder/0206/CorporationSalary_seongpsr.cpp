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

i64 salary[55];

// 시작점을 구할 수 없다!
// 그냥 모든 경우 다 확인하기로 (어차피 이미 구한 값이면 바로 return 할테니)

class CorporationSalary {

public:
    // 전부 N인 말단직원인지 확인
    bool isLeaf(string relation) {
        for (char c: relation) {
            if (c == 'Y')
                return false;
        }
        return true;
    }

    i64 dp(int nowIdx, vector<string> &relations) {
        auto& res = salary[nowIdx];
        
        if (res != 0) // 이미 계산된 값이라면 바로 리턴
            return res;
        if (isLeaf(relations[nowIdx])) // 말단 직원이라면 1 리턴
            return res = 1;
        
        i64 sum = 0;
        for (int i = 0; i < relations[nowIdx].size(); i++) {
            if (relations[nowIdx][i] == 'Y') // 직원의 급여 계산
                sum += dp(i, relations);
        }
        
        return res = sum;
    }


    i64 totalSalary(vector<string> relations) {
        memset(salary, 0, sizeof(salary));

        i64 ans = 0;
        for (int i = 0; i < relations.size(); i++) {
           ans += dp(i, relations);
        }
        
        return ans;
    }
};

int main() {

    CorporationSalary cs;

    cout<<cs.totalSalary({"N"})<<endl; // 1
    cout<<cs.totalSalary({"NNYN", "NNYN", "NNNN", "NYYN"})<<endl; // 5
    cout<<cs.totalSalary({"NNNNNN", "YNYNNY", "YNNNNY", "NNNNNN", "YNYNNN", "YNNYNN"})<<endl; // 17
    cout<<cs.totalSalary({"NYNNYN", "NNNNNN", "NNNNNN", "NNYNNN", "NNNNNN", "NNNYYN"})<<endl; // 8
    cout<<cs.totalSalary({"NNNN", "NNNN", "NNNN", "NNNN"})<<endl; // 4

    return 0;
}