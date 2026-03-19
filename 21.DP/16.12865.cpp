#include <iostream>
#include <vector>
using namespace std;
struct Bag {
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
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= k; w++) {
            if(bag[i].w > w) dp[i][w] = dp[i-1][w];
            else dp[i][w] = max(dp[i-1][w], bag[i].v + dp[i-1][w - bag[i].w]);
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}
