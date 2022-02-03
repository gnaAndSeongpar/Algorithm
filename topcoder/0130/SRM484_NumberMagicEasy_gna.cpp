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


bool check[16];
bool card[4][16] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
    {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}};


class NumberMagicEasy {

public:

    void yes(int ncard) {

        for (int i=1; i<=15; i++) {
            if (card[ncard][i] && check[i]) check[i] = true;
            else check[i] = false;
        }
    }

    void no(int ncard) {

        for (int i=1; i<=15; i++) {
            if (!card[ncard][i] && check[i]) check[i] = true;
            else check[i] = false;
        }
    }

    int theNumber(string answer) {

        memset(check, true, sizeof(check));

        for (int i=0; i<4; i++) {
            if (answer[i] == 'Y') yes(i);
            else if (answer[i] == 'N') no(i);
        }

        for (int i=1; i<=15; i++) {
            if (!check[i]) continue;
            return i;
        }
        return 16;
    }
};


int main() {

    NumberMagicEasy magic;
    cout<<magic.theNumber("YNYY")<<endl;
    cout<<magic.theNumber("YNNN")<<endl;
    cout<<magic.theNumber("NNNN")<<endl;
    cout<<magic.theNumber("YYYY")<<endl;
    cout<<magic.theNumber("NYNY")<<endl;
    return 0;
}
