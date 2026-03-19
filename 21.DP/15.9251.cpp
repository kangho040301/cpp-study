#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1,vector<int>(m + 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}