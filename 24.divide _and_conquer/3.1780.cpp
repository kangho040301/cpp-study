#include <iostream>
#include <vector>
using namespace std;
int m1 = 0; int zero = 0; int p1 = 0;
bool check(vector<vector<int>> &v, int size, int r, int c) {
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            if(v[i][j] != v[r][c]) return false;
        }
    }
    return true;
}
void solve(vector<vector<int>> &v, int size, int r, int c) {
    if(check(v, size, r, c)) {
        if(v[r][c] == -1) m1++;
        else if(v[r][c] == 0) zero++;
        else p1++;
        return;
    }
    for(int i = r; i < r + size; i += size/3) {
        for(int j = c; j < c + size; j += size/3) {
            solve(v, size/3, i, j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    solve(v, n, 0, 0);
    cout << m1 << '\n' << zero << '\n' << p1 << '\n';
    return 0;
}