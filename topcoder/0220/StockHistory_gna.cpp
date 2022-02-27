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


class StockHistory {

public:

    vector<double> split(string s) {

        vector<double> v;

        int i = 0;
        while (s[i] != '\0') {
            string tmp = "";
            while (s[i] != ' ' && s[i] != '\0')
                tmp.push_back(s[i++]);
            v.push_back(stod(tmp));
            if (s[i] == '\0') break;
            i++;
        }
        return v;
    }

    
    int maximumEarnings(int initialInvestmnet, int monthlyContribution, vector<string> stockPrices) {

        double mx = 1;
        int sz = stockPrices.size();
        vector<double> vlast = split(stockPrices[sz-1]);

        double tot = 0;
        for (int i=sz-2; i>=0; i--) {
            vector<double> v = split(stockPrices[i]);
            for (int j=0; j<v.size(); j++)
                mx = max(mx, vlast[j]/v[j]);
            if (i == 0) tot += initialInvestmnet*(mx-1);
            else tot += monthlyContribution*(mx-1);
        }
        return tot;
    }
};


int main() {

    StockHistory hist;
    cout<<hist.maximumEarnings(100, 20, {"40 50 60", "37 48 55", "100 48 50", "105 48 47", "110 50 52", "110 50 52", "110 51 54", "109 49 53"})<<endl;
    cout<<hist.maximumEarnings(1000, 0, {"10 20 30", "15 24 42"})<<endl;
    cout<<hist.maximumEarnings(1000, 0, {"10", "9"})<<endl;
}