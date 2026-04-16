#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int,int>>> adj;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, x; cin >> n >> m >> x;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<pair<int,int>>> rev_adj(n+1);
    vector<int> dist_go(n+1, 1e8);
    vector<int> dist_back(n+1, 1e8);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, x});
    while(!q.empty()) {
        int cnt_t = q.top().first;
        int cnt_n = q.top().second;
        q.pop();

        if(dist_go[cnt_n] < cnt_t) continue;

        for(auto& next : rev_adj[cnt_n]) {
            if(dist_go[next.first] > cnt_t + next.second) {
                dist_go[next.first] = cnt_t + next.second;
                q.push({cnt_t + next.second, next.first});
            }
        }
    }

    q.push({0, x});
    while(!q.empty()) {
        int cnt_t = q.top().first;
        int cnt_n = q.top().second;
        q.pop();

        if(dist_back[cnt_n] < cnt_t) continue;

        for(auto& next : adj[cnt_n]) {
            if(dist_back[next.first] > cnt_t + next.second) {
                dist_back[next.first] = cnt_t + next.second;
                q.push({cnt_t + next.second, next.first});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i == x) continue;
        ans = max(ans, dist_go[i] + dist_back[i]);
    }
    cout << ans << '\n';
    return 0;
}