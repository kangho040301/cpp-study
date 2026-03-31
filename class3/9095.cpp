#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    int dp[11]{};
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(int i = 4; i <= 10; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    while(t--) {
        int x; cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}
/*
n = 0; 0
n = 1; 1
1

n = 2; 2
1 1
2

n = 3; 4
1 1 1
2 1
1 2
3

n = 4; 7
1 1 1 1
2 1 1
1 2 1
3 1
1 1 2
2 2
1 3

n = 5; 13
1 1 1 1 1
2 1 1 1
1 2 1 1
3 1 1
1 1 2 1
2 2 1
1 3 1
1 1 1 2
2 1 2
1 2 2
3 2
1 1 3
2 3
*/