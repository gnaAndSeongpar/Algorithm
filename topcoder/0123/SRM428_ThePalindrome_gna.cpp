#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

class ThePalindrome {

public:
    int find(string s) {

        for (int i=s.size(); i<2*s.size(); i++) {
            
            bool check = true;
            for (int j=0; j<s.size(); j++) {
                if (i-1-j < s.size() && s[j] != s[i-1-j]) {
                    check = false;
                    break;
                }
            }
            if (check) return i;
        }
        return 2*s.size()-1;
    }
};

int main() {

    ThePalindrome p;
    cout<<p.find("abab")<<endl; // 5
    cout<<p.find("abacaba")<<endl; // 7
    cout<<p.find("qwerty")<<endl; // 11
    cout<<p.find("abdfhdyrbdbsdfghjkllkjhgfds")<<endl; // 38
    return 0;
}