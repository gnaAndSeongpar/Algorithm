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

long long dp[51];

class CorporationSalary {

public:
    long long totalSalary(vector<string> relations) {

        int N = relations.size();
        memset(dp, 0, sizeof(dp));

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) { //j번째 사람의 연봉 구하기
                if (dp[j]) continue;

                bool check = true;
                long long salary = 0;
                for (int k=0; k<N; k++) {
                    if (relations[j][k] == 'N') continue;
                    if (!dp[k]) { //k번째 사람을 부하로 두고 있지만 아직 k번째 사람의 연봉을 모르는 경우
                        check = false;
                        break;
                    }
                    salary += dp[k];
                }
                if (check) dp[j] = !salary ? 1 : salary; //부하가 없을 때는 연봉을 1로 처리
            }
        }
        
        long long re = 0;
        for (int i=0; i<N; i++) re += dp[i];
        return re;
    }
};

int main() {

    CorporationSalary s;
    cout<<s.totalSalary({"N"})<<endl; //1
    cout<<s.totalSalary({"NNYN", "NNYN", "NNNN", "NYYN"})<<endl; //5
    cout<<s.totalSalary({"NNNNNN", "YNYNNY", "YNNNNY", "NNNNNN", "YNYNNN", "YNNYNN"})<<endl; //17
    cout<<s.totalSalary({"NYNNYN", "NNNNNN", "NNNNNN", "NNYNNN", "NNNNNN", "NNNYYN"})<<endl; //8
    cout<<s.totalSalary({"NNNN", "NNNN", "NNNN", "NNNN"}); //4
    return 0;
}