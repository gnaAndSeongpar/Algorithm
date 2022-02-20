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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

class ColorfulBoxesAndBalls {

public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {

        int nchangable = min(numRed, numBlue);
        int re = numRed*onlyRed+numBlue*onlyBlue;
        
        for (int i=1; i<=nchangable; i++) {
            int score = (numRed-i)*onlyRed+(numBlue-i)*onlyBlue+2*i*bothColors;
            re = max(re, score);
        }
        return re;
    }
};

int main() {

    ColorfulBoxesAndBalls color;
    cout<<color.getMaximum(2, 3, 100, 400, 200)<<endl;
    cout<<color.getMaximum(2, 3, 100, 400, 300)<<endl;
    cout<<color.getMaximum(5, 5, 464, 464, 464)<<endl;
    cout<<color.getMaximum(1, 4, 20, -30, -10)<<endl;
    cout<<color.getMaximum(9, 1, -1, -10, 4)<<endl;
}