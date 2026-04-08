#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int k; cin >> k;
        vector<int> cost(k+1);
        vector<int> sum(k+1);
        for(int i = 1; i <= k; i++) {
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        //dp[i][j] : i ~ j 합치는 최소 비용
        vector<vector<int>> dp(k+1,vector<int>(k+1));
        for(int len = 1; len < k; len++) {
            for(int i = 1; i + len <= k; i++) { // i : 시작점
                int j = i + len; // j : 끝점
                
                dp[i][j] = 2e9;
                for(int m = i; m < j; m++) {
                    dp[i][j] = min(dp[i][j],dp[i][m] + dp[m+1][j] + (sum[j] - sum[i-1]));
                }
            }
        }
        cout << dp[1][k] << '\n';
    }
    return 0;
}