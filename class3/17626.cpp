#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> dp(n+1,5);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i],dp[i-j*j] + 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}