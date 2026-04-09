#include <iostream>
#include <vector>
using namespace std;
struct App{
    int size, cost;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<App> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].size;
    }
    int max_cost = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].cost;
        max_cost += a[i].cost;
    }
    vector<int> dp(max_cost + 1); //dp[i] : cost가 i일때 확보가능한 최대 바이트
    for(int i = 1; i <= n; i++) {
        for(int c = max_cost; c - a[i].cost >= 0; c--) {
            dp[c] = max(dp[c], dp[c - a[i].cost] + a[i].size);
        }
    }
    for(int i = 0; i <= max_cost; i++) {
        if(dp[i] >= m) {
            cout << i << '\n';
            return 0;
        }
    }
}
