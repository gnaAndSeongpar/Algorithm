#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

class NotTwo {

public:
    int maxStones(int width, int height) {

        vector<vector<bool>> check(1005, vector<bool>(1005, false));
        
        int cnt = 0;
        for (int i=0; i<width; i++) {
            for (int j=0; j<height; j++) {
                if (check[i][j]) continue;
                if (i >= 2) check[i-2][j] = true;
                if (i+2 < width) check[i+2][j] = true;
                if (j >=2) check[i][j-2] = true;
                if (j+2 < height) check[i][j+2] = true;
                cnt++;
            }
        }

        return cnt;
    }
};

int main() {

    NotTwo nt;
    cout<<nt.maxStones(3, 2)<<endl; //4
    cout<<nt.maxStones(3, 3)<<endl; //5
    cout<<nt.maxStones(8, 5)<<endl; //20
    cout<<nt.maxStones(10, 10)<<endl; //52
    return 0;
}
