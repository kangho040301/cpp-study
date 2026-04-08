#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dfs(vector<vector<int>>& h, vector<vector<int>>& dp, int cntx, int cnty) {
    if(cntx == n && cnty == m) {
        return 1;
    }
    if(dp[cntx][cnty] != -1) return dp[cntx][cnty];
    dp[cntx][cnty] = 0;
    for(int i = 0; i < 4; i++) {
        int nextx = cntx + dx[i];
        int nexty = cnty + dy[i];
        if(h[nextx][nexty] < h[cntx][cnty]) {
            dp[cntx][cnty] += dfs(h, dp, nextx, nexty);
        }
    }
    return dp[cntx][cnty];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    vector<vector<int>> height(n+2,vector<int>(m+2,1e9));
    vector<vector<int>> dp(n+2,vector<int>(m+2,-1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> height[i][j];
        }
    }
    dfs(height,dp,1,1);
    cout << dp[1][1] << '\n';
    return 0;
}