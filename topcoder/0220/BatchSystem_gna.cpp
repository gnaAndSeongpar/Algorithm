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


class BatchSystem {

public:

    vector<int> schedule(vector<int> duration, vector<string> user) {

        vector<ii> tmp;
        for (int i=0; i<user.size(); i++) {
            int t = 0;
            for (int j=0; j<user.size(); j++) {
                if (user[i] == user[j]) t += duration[i];
            }
            tmp.push_back({t, i});
        }
        stable_sort(tmp.begin(), tmp.end());

        vector<int> v;
        for (int i=0; i<tmp.size(); i++) v.push_back(tmp[i].Y);
        return v;
    }
};


void printvec(vector<int>& vec) {

    for (int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}


int main() {

    BatchSystem sys;
    vector<int> v;
    v = sys.schedule({400, 100, 100, 100}, {"Danny", "Stella", "Stella", "Mac"});
    printvec(v);

    v = sys.schedule({200, 200, 200}, {"Gil", "Sarah", "Warrick"});
    printvec(v);
    
    v = sys.schedule({100, 200, 50}, {"Horatio Caine", "horatio caine", "YEAAAAAAAAH"});
    printvec(v);
    return 0;
}   