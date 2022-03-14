#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


class AutoLoan {

public:

    double binarySearch(double price, double monthlyPayment, int loanTerm) {

        double first = 0;
        double last = 100;
        double mid, bal;

        while ((1e-9 < last-first) && (1e-9 < (last-first)/last)) { // while (first <= last)로 두면 무한루프
            mid = (first+last)/2;
            bal = price;
            for (int i=0; i<loanTerm; i++) {
                bal = bal+bal*mid/1200;
                bal -= monthlyPayment;
            }
            if (bal > 0) last = mid;
            else first = mid;
        }
        return mid;
    }

    double interestRate(double price, double monthlyPayment, int loanTerm) {
        return binarySearch(price, monthlyPayment, loanTerm);
    }
};


int main() {

    AutoLoan loan;
    cout<<loan.interestRate(6800, 100, 68)<<endl;
    cout<<loan.interestRate(2000, 510, 4)<<endl;
    return 0;
}