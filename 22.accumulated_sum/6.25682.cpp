#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n+1,vector<int>(m+1));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) { // 왼쪽 위가 'B'일 때 고쳐야 하는 곳
            if((i+j)%2 == 0 && s[j] == 'W') {
                board[i+1][j+1] = 1;
            }
            if((i+j)%2 == 1 && s[j] == 'B') {
                board[i+1][j+1] = 1;
            }
        }
    }
    vector<vector<int>> sum(n+1,vector<int>(m+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + board[i][j];
        }
    }
    int minNum = min(k*k - sum[k][k],sum[k][k]);
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            int changeNum = sum[i][j] - sum[i][j-k] - sum[i-k][j] + sum[i-k][j-k];
            changeNum = min(k*k - changeNum, changeNum);
            if(changeNum < minNum) minNum = changeNum;
        }
    }
    cout << minNum << '\n';
    return 0;
}