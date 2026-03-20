#include <iostream>
#include <vector>
using namespace std;
struct Bag { // 무게, 가치
    int w, v;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<Bag> bag(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> bag[i].w >> bag[i].v;
    }
    //dp[i][w]; w를 더 들 수 있을 때 i까지의 최대 가치
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= k; w++) {
            //i번째 가방을 들 수 없음
            if(bag[i].w > w) dp[i][w] = dp[i-1][w]; // 직전 가방까지 최대 가치
            //i번째 가방을 들 수 있다면, 안 들고 w 유지 vs i번째 가방 무게만큼 쓰고 가치+ 중에 큰 것
            else dp[i][w] = max(dp[i-1][w], bag[i].v + dp[i-1][w - bag[i].w]);
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}
/*
ex) n = 2, k = 3;
bag[1].w = 1 bag[1].v = 2;
bag[2].w = 2 bag[3].v = 3;
i = 1, w = 1
-> bag[1].w <= 1, dp[0][1] vs bag[1].v + dp[0][1 - bag[1].w] 0 vs 2 = 2
dp[1][1] = 2;
i = 1, w = 2
-> bag[1].w <= 2, dp[0][2] vs bag[1].v + dp[0][2 - bag[1].w] 0 vs 2 = 2
dp[1][2] = 2;
i = 1, w = 3
dp[1][3] = 2;
i = 2, w = 1;
-> bag[2].w > 1, dp[2][1] = dp[1][1] = 2;
i = 2, w = 2;
-> bag[2].w <= 2, dp[1][2] vs bag[2].v + dp[1][2 - bag[2].w] 2 vs 3 = 3
dp[2][2] = 3;
i = 2, w = 3;
-> bag[2].w <= 3, dp[1][2] vs bag[2].v + dp[1][3 - bag[2].w] 2 vs (3 + 2) = 5
dp[2][3] = 5;
*/
