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

class StockHistory {

public:

    vector<string> split(string s, char c){
        stringstream ss(s); 
     
        string word;
        vector<string> result;
        while (getline(ss, word, c)) { 
            result.push_back(word);
        }
        
        return result;
    }
    
    void printVector(vector<int> &v) {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }


    int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices) {
        int month = stockPrices.size();
        int money = initialInvestment;
        vector<int> v[55];
        
        for (int i = 0; i < stockPrices.size(); i++) {
            vector<string> res = split(stockPrices[i], ' ');
            for (int j = 0; j < res.size(); j++)
                v[i].push_back(stoi(res[j]));
        }
        
        double maxv = 0.0;
        vector<bool> buy(month);
        vector<double> proportion(month);
        for (int i = month - 2; i >= 0; i--) {
            for (int j = 0; j < v[i].size(); j++) {
                double p = 1.0 * v[month - 1][j] / v[i][j] - 1;
                if (0 < p && maxv < p) {
                    buy[i] = true;
                    maxv = p;
                    proportion[i] = p;
                }
            }
        }
        
        double ans = 0.0;
        for (int i = 0; i < month; i++) {
            if (buy[i]) {
                ans += money * proportion[i];
                money = 0;
            }
            money += monthlyContribution;
        }
        
        return (int)round(ans);
    }
};

int main() {

    StockHistory sh;

    cout<<sh.maximumEarnings(1000, 0, {"10 20 30", "15 24 32"})<<endl; // 500
    cout<<sh.maximumEarnings(1000, 0, {"10", "9"})<<endl; // 0
    cout<<sh.maximumEarnings(100, 20, {"40 50 60", "37 48 55", "100 48 50", "105 48 47", "110 50 52", "110 50 52", "110 51 54", "109 49 53"})<<endl; // 239

    return 0;
}