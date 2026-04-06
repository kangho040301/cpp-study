#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e8));
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if(dist[u][v] > w) dist[u][v] = w; //u - v 거리는 w
    }
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    //플로이드-워셜 알고리즘 (n이 작을때)
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] >= 1e8) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}