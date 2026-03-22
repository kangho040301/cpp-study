#include <iostream>
#include <vector>
using namespace std;
int white = 0;
int blue = 0;
bool check(vector<vector<int>> &paper, int r, int c, int n) {
    for(int x = r; x < r + n; x++) {
        for(int y = c; y < c + n; y++) {
            if(paper[x][y] != paper[r][c]) return false;
        }
    }
    return true;
}
void cut(vector<vector<int>> &paper, int n, int r, int c) {
    if(check(paper, r, c, n)) {
        if(paper[r][c]) blue++;
        else white++;
        return;
    }
    for(int i = r; i < r + n; i += n/2) {
        for(int j = c; j < c + n; j += n/2) {
        
            cut(paper, n/2, i, j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> paper(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    cut(paper, n, 0, 0);
    cout << white << '\n' << blue << '\n';
    return 0;
}