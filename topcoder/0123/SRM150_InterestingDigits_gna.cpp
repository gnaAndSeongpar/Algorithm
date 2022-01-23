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


class InterestingDigits {

public:
    vector<int> digits(int base) {

        vector<int> re;

        for (int i=2; i<base; i++) {

            int check = 1;
            for (int j=1; j<=9999; j++) {
                if (j%i) continue;

                int tmp = j, s = 0;
                while (tmp) {
                    s += tmp%base;
                    tmp /= base; 
                }
                if (s%i) {
                    check = 0;
                    break;
                }
            }
            if (check) re.push_back(i);
        }
        return re;
    }
};

int main() {

    InterestingDigits d;    
    
    vector<int> re = d.digits(10); //{3, 9}
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;

    re = d.digits(3); //{2}
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;

    re = d.digits(9); //{2, 4, 8}
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;

    re = d.digits(26); //{5, 25}
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;

    re = d.digits(30); //{29}
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;

    return 0;
}