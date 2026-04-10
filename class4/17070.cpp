#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[18][18][4];
int house[18][18];
int n;
int dfs(int cntx, int cnty, int state) { //state 1 : 가로, 2 : 세로, 3 : 대각선
    if(cntx == n && cnty == n) {
        return 1;
    }
    if(dp[cntx][cnty][state] != -1) return dp[cntx][cnty][state];

    dp[cntx][cnty][state] = 0;
    switch(state) {
        case 1 :
            if(house[cntx][cnty + 1] == 0) {
                dp[cntx][cnty][state] += dfs(cntx,cnty + 1, 1);
                if(house[cntx + 1][cnty + 1] == 0 && house[cntx + 1][cnty] == 0) {
                    dp[cntx][cnty][state] += dfs(cntx + 1,cnty + 1, 3);
                }
            }
            break;
        case 2 :
            if(house[cntx + 1][cnty] == 0) {
                dp[cntx][cnty][state] += dfs(cntx + 1,cnty, 2);
                if(house[cntx + 1][cnty + 1] == 0 && house[cntx][cnty + 1] == 0) {
                    dp[cntx][cnty][state] += dfs(cntx + 1,cnty + 1, 3);
                }
            }
            break;
        case 3 :
            if(house[cntx][cnty + 1] == 0) {
                dp[cntx][cnty][state] += dfs(cntx,cnty + 1, 1);
            }
            if(house[cntx + 1][cnty] == 0) {
                dp[cntx][cnty][state] += dfs(cntx + 1,cnty, 2);
            }
            if(house[cntx][cnty + 1] == 0 && house[cntx + 1][cnty] == 0 && house[cntx + 1][cnty + 1] == 0) {
                dp[cntx][cnty][state] += dfs(cntx + 1,cnty + 1, 3);
            }
    }
    return dp[cntx][cnty][state];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    memset(dp,-1,sizeof(dp));
    fill(&house[0][0], &house[0][0] + 18*18, 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }
    cout << dfs(1,2,1) << '\n';
    return 0;
}
