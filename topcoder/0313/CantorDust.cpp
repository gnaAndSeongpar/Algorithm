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

class CantorDust {

public:

    string getLine(int time) {

        if (!time) return "X";
        string s = getLine(time-1);
        return s+string(s.size(), ' ')+s;
    }

    vector<vector<char>> getBoard(int time) {

        string line = getLine(time);
        int sz = line.size();
        vector<vector<char>> board(sz, vector<char>(sz));

        for (int i=0; i<sz; i++) {
            for (int j=0; j<sz; j++) {
                if (line[i]=='X' && line[j] == 'X') board[i][j] = 'X';
                else board[i][j] = '.';
            }
        }
        return board;
    }

    bool ispattern(int x, int y, vector<vector<char>> board, vector<string> pattern) {
        
        int bh = board.size();
        int ph = pattern.size(), pw = pattern[0].size();

        for (int i=0; i<ph; i++) {
            for (int j=0; j<pw; j++) {
                if (x+i < 0 || x+i >= bh || y+j < 0 || y+j >= bh) return false;
                if (pattern[i][j] != board[x+i][y+j]) return false;
            }
        }
        return true;
    }

    int occurrencesNumber(vector<string> pattern, int time) {

        vector<vector<char>> board = getBoard(time);

        int cnt = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board.size(); j++) {
                if (ispattern(i, j, board, pattern)) cnt++;
            }
        }
        return  cnt;
    }
};

int main() {

    CantorDust dust;
    cout<<dust.occurrencesNumber({".X", ".."}, 1)<<endl; //1
    cout<<dust.occurrencesNumber({".."}, 1)<<endl; //2
    cout<<dust.occurrencesNumber({"."}, 2)<<endl; //65
    cout<<dust.occurrencesNumber({"X...X"}, 2)<<endl; //4
    cout<<dust.occurrencesNumber({"X"}, 9)<<endl; //262144

    return 0;
}