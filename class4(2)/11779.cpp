#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> cost(n+1, 1e8);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    int from, to; cin >> from >> to;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> parent(n+1);
    q.push({0, from});
    cost[from] = 0;
    int ans = 1e8;
    while(!q.empty()) {
        int acc_cost = q.top().first;
        int cnt_city = q.top().second;
        q.pop();

        if(cost[cnt_city] < acc_cost) continue;

        if(cnt_city == to) {
            ans = min(ans, cost[to]);
        }
        for(auto& next : adj[cnt_city]) {
            if(cost[next.first] > acc_cost + next.second) {
                cost[next.first] = acc_cost + next.second;
                parent[next.first] = cnt_city;
                q.push({cost[next.first], next.first});
            }
        }
    }
    vector<int> path(1,to);
    while(path.back() != from) {
        path.push_back(parent[path.back()]);
    }
    cout << cost[to] << '\n' << path.size() << '\n';
    for(int i = path.size() - 1; i >= 0 ; i--) {
        cout << path[i] << ' ';
    }
    cout << '\n';
    return 0;
}
