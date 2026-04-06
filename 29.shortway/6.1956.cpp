#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e8));
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 1e8;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dist[i][i]);
    }
    if(ans == 1e8) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}