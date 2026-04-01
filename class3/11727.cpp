#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1, dp[2] = 3;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    }
    cout << dp[n] << '\n';
    return 0;
}
/*
n = 1; 1
n = 2; 3
n = 3; 3 + 1*2
n = 4; 5 + 3*2
n = 5; 11 + 5*2 = 21
*/