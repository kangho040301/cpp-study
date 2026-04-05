#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int shortway(vector<vector<pair<int,int>>>& adj,int start, int end) {
    vector<int> dist(801,1e8);
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()) {
        int d = pq.top().first;
        int cnt = pq.top().second;
        pq.pop();

        if(dist[cnt] < d) continue;
        for(auto & next : adj[cnt]) {
            int next_node = next.first;
            int length = next.second;

            if(dist[next_node] > d + length) {
                dist[next_node] = d + length;
                pq.push({dist[next_node],next_node});
            }
        }
    }
    return dist[end];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1); //{정점,거리}
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int v1, v2; cin >> v1 >> v2;
    int path1 = shortway(adj,1,v1) + shortway(adj,v1,v2) + shortway(adj,v2,n);
    int path2 = shortway(adj,1,v2) + shortway(adj,v2,v1) + shortway(adj,v1,n);
    int ans = min(path1,path2);
    if(ans >= 1e8) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}