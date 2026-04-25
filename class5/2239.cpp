#include <iostream>
#include <string>
#include <vector>
using namespace std;
int board[9][9];
vector<pair<int,int>> zero;
bool check(int r, int c, int x) {
    for(int i = 0; i < 9; i++) { // + 확인
        if(board[i][c] == x) return false;
        if(board[r][i] == x) return false;
    }
    for(int a = (r/3)*3; a < (r/3)*3 + 3; a++) { // 3x3 확인
        for(int b = (c/3)*3; b < (c/3)*3 + 3; b++) {
            if(board[a][b] == x) return false;
        }
    }
    return true;
    
}
void solve(int cnt) {
    if(cnt == zero.size()) {
        for(int a = 0; a < 9; a++) {
            for(int b = 0; b < 9; b++) {
                cout << board[a][b];
            }
            cout << '\n';
        }
        exit(0);
    }

    int r = zero[cnt].first;
    int c = zero[cnt].second;

    for(int i = 1; i <= 9; i++) {
        if(check(r, c, i)) {
            board[r][c] = i;
            solve(cnt + 1);
            board[r][c] = 0;
        }

    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<string> v(9);
    for(int i = 0; i < 9; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            board[i][j] = v[i][j] - '0';
            if(board[i][j] == 0) zero.push_back({i,j});
        }
    }

    solve(0);
    return 0;
}