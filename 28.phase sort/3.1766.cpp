#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> degree(n+1,0);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
    }

    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int cnt = q.top(); q.pop();
        cout << cnt << ' ';

        for(int next : adj[cnt]) {
            degree[next]--;
            if(degree[next] == 0) q.push(next);
        }
    }
    return 0;
}