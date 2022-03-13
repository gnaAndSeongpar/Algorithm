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

class BinaryFlips {
public:

    int minimalMoves(int A, int B, int K) {
        for (i64 i = 0; i <= A + B; i++) {
            i64 rest  = i * K - A;
            i64 use = ((i / 2) * B + (i - 1) / 2 * A) * 2;
            if (rest >= 0 && rest % 2 == 0 && rest <= use)
                return (int) i;
        }
        return -1;
    }
};

int main() {

    BinaryFlips bf;

    cout<<bf.minimalMoves(3, 0, 3)<<endl; // 1
    cout<<bf.minimalMoves(4, 0, 3)<<endl; // 4
    cout<<bf.minimalMoves(4, 1, 3)<<endl; // 2
    cout<<bf.minimalMoves(3, 2, 5)<<endl; // -1
    cout<<bf.minimalMoves(100000, 100000, 578)<<endl; // 174
    cout<<bf.minimalMoves(0, 0, 1)<<endl; // 0
    cout<<bf.minimalMoves(4, 44, 50)<<endl; // -1

    return 0;
}