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

class AutoLoan {


public:

    double calcBalance(double x, double price, double monthlyPayment, int loanTerm) {
        double balance = price;

        for (int i = 0; i < loanTerm; i++) { // loanTerm 기간만큼 계산
            balance *= x / 1200 + 1;
            balance -= monthlyPayment;
        }

        return balance;
    }

    double interestRate(double price, double monthlyPayment, int loanTerm) {
        double high = 100;
        double low = 0;
        double mid;

        for (int i = 0; i < 100; i++) {
            mid = (high + low) / 2;

            if (calcBalance(mid, price, monthlyPayment, loanTerm) > 0)
                high = mid;
            else
                low = mid;
        }

        return mid;
    }
};

int main() {

    AutoLoan al;

    cout<<al.interestRate(6800, 100, 68)<<endl; // 1.3322616182218813E-13
    cout<<al.interestRate(2000, 510, 4)<<endl; // 9.56205462458368
    cout<<al.interestRate(15000, 364, 48)<<endl; // 7.687856394581649

    return 0;
}