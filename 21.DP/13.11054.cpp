#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    vector<vector<int>> dp(2,vector<int>(n,1));
    int max_dp0 = 0;
    int max_dp1 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j]) {
                if(dp[0][j] > max_dp0) max_dp0 = dp[0][j];
            }
            else if(array[i] < array[j]) {
                if(max(dp[0][j],dp[1][j]) > max_dp1) max_dp1 = max(dp[0][j],dp[1][j]);
            }
        }
        dp[0][i] = max_dp0 + 1;
        dp[1][i] = max_dp1 + 1;
        max_dp0 = 0;
        max_dp1 = 0;
    }
    auto it1 = max_element(dp[0].begin(),dp[0].end());
    auto it2 = max_element(dp[1].begin(),dp[1].end());
    int ans = max(*it1, *it2);
    cout << ans << '\n';
    return 0;
}