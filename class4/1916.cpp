#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> mincost(n+1,1e8);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w}); //{다음 정점, 비용}
    }
    int start, end; cin >> start >> end;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start}); //{누적비용, 정점}
    while(!q.empty()) {
        int acc = q.top().first;
        int cnt = q.top().second;
        q.pop();

        if(mincost[cnt] < acc) continue;
        for(auto& next : adj[cnt]) {
            int next_node = next.first;
            int cost = next.second;

            if(mincost[next_node] > acc + cost) {
                mincost[next_node] = acc + cost;
                q.push({acc + cost,next_node});
            }
        }
    }
    cout << mincost[end] << '\n';
    return 0;
}