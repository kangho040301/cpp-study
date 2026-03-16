#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> plate(9,vector<int>(9));
vector<pair<int,int>> zero;
bool check(int x, int y, int i) {
    for(int a : plate[x]) {
        if(i == a) return false;
    }
    for(int a = 0; a < 9; a++) {
        if(i == plate[a][y]) return false;
    }
    x /= 3; y /= 3;
    for(int a = x*3; a < x*3 + 3; a++) {
        for(int b = y*3; b < y*3 + 3; b++) {
            if(i == plate[a][b]) return false;
        }
    }
    return true;
}
void sudoku(int cnt) {
    int x = zero[cnt].first;
    int y = zero[cnt].second;
    for(int i = 1; i <= 9; i++) {
        if(check(x, y ,i)) {
            plate[x][y] = i;
            
            if(cnt + 1 == zero.size()) {
                for(int i = 0; i < 9; i++) {
                    for(int j = 0; j < 9; j++) {
                        cout << plate[i][j] << ' ';
                    }
                cout << '\n';
                }
            exit(0);
            }
            
            sudoku(cnt + 1);
            plate[x][y] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> plate[i][j];
            if(plate[i][j] == 0) {
                zero.push_back({i,j}); 
            }
        }
    }

    sudoku(0);
}