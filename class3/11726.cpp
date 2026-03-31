#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    int dp[1001]{};
    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout << dp[n] << '\n';
    return 0;
}
/*
n = 2; 2
1 1
2
n = 3; 3
1 1 1
1 2
2 1
n = 4; 5
1 1 1 1
1 1 2
1 2 1
2 1 1
2 2
n = 5; 8
1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
2 1 1 1 
1 2 2
2 1 2
2 2 1
fibo zz
*/