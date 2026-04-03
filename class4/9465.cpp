#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> point(2,vector<int>(n+1));
        vector<vector<int>> dp(n+1,vector<int>(3));
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> point[i][j];
            }
        }

        for(int i = 1; i <= n; i++) {
            //i의 스티커를 안땜
            dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}); 
            //i의 위쪽 스티커 땜
            dp[i][1] = point[0][i] + max(dp[i-1][0],dp[i-1][2]);
            //i의 아래쪽 스티커 땜
            dp[i][2] = point[1][i] + max(dp[i-1][0],dp[i-1][1]);
        }
        cout << max({dp[n][0],dp[n][1],dp[n][2]}) << '\n';
    }
    return 0;
}