#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int,int>> m(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    //dp[i][j] : i ~ j 행렬곱의 최소 연산 수
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int len = 1; len < n; len++) {
        for(int i = 1; i + len <= n; i++) {
            int j = i + len;

            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + m[i].first*m[k].second*m[j].second);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}