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

class BinaryFlips {

public:
    int minimalMoves(int A, int B, int K) {

        for (long long i=0; i<=A+B; i++) {
            long long rest = i*K-A; 
            long use = ((i/2)*B+((i-1)/2)*A)*2;
            if (rest >= 0 && rest%2==0 && rest <= use) return i;
        }   
        return -1;
    }
};

int main() {

    BinaryFlips flips;
    cout<<flips.minimalMoves(3, 0, 3)<<endl; //1
    cout<<flips.minimalMoves(4, 0, 3)<<endl; //4
    cout<<flips.minimalMoves(4, 1, 3)<<endl; //2
    cout<<flips.minimalMoves(3, 2, 5)<<endl; //-1
}