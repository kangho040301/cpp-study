#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int visited[100001];
int order = 1;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m , r; cin >> n >> m >> r;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        sort(graph[i].rbegin(),graph[i].rend());
    }

    queue<int> q;
    visited[r] = order++;
    q.push(r);
    while(!q.empty()) {
        int cnt = q.front(); q.pop();
        for(int next : graph[cnt]) {
            if(!visited[next]) {
                visited[next] = order++;
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
    return 0;
}