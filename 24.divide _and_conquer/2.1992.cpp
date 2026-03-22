#include <iostream>
#include <vector>
#include <string>
using namespace std;
string ans = "";
bool check(vector<vector<int>> &v, int size, int r, int c) {
    for(int x = r; x < r + size; x++) {
        for(int y = c; y < c + size; y++) {
            if(v[x][y] != v[r][c]) return false;
        }
    }
    return true;
}
void solve(vector<vector<int>> &v, int size, int r, int c) {
    if(check(v, size, r, c)) {
        if(v[r][c]) ans += "1";
        else ans += "0";
        return;
    }
    else {
        ans += "(";
        for(int i = r; i < r + size; i += size/2) {
            for(int j = c; j < c + size; j += size/2) {
                solve(v, size/2, i, j);
            }
        }
        ans += ")";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            v[i][j] = s[j] - '0';
        }
    }
    solve(v, n, 0, 0);
    cout << ans << '\n';
}