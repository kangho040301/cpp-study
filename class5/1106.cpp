#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int c, n; cin >> c >> n;
    vector<int> dp(c+101, 1e9); //dp[i] : i명을 더 늘리기 위해 필요한 최소 비용
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int cost, n; cin >> cost >> n;

        for(int j = n; j <= c+100; j++) {
            if(dp[j - n] != 1e9) {
                dp[j] = min(dp[j], dp[j - n] + cost);
            }
        }
    }

    int ans = 1e9;
    for(int i = c; i <= c+100; i++) {
        if(dp[i] < ans) ans = dp[i];
    }
    cout << ans << '\n';
    return 0;
}