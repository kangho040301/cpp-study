#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int cards[1001];
int dp[1001][1001][2];
int solve(int L, int R,bool turn) {
    if(L > R) return 0;
    if(dp[L][R][turn] != -1) return dp[L][R][turn];
    if(turn) { 
        return dp[L][R][turn] = max(cards[L] + solve(L+1,R,!turn),
                                    cards[R] + solve(L,R-1,!turn));
    }
    else {
        return dp[L][R][turn] = min(solve(L+1,R,!turn),
                                    solve(L,R-1,!turn));
    }

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> cards[i];
        }
        cout << solve(1,n,true) << '\n';
    }
    return 0;
}