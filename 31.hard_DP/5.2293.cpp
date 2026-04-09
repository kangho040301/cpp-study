#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> dp(k+1);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        for(int j = 1; j <= k; j++) {
            if(j - v >= 0) {
                dp[j] += dp[j - v];
            }
        }
    }
    cout << dp[k] << '\n';
    return 0;
}