#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool d_v[100001];
int d_order = 1;
bool b_v[100001];
int b_order = 1;
void dfs(vector<vector<int>> &graph, int cnt) {
    d_v[cnt] = true;
    cout << cnt << ' ';
    for(int next : graph[cnt]) {
        if(!d_v[next]) dfs(graph, next);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, v; cin >> n >> m >> v;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(graph, v);
    cout << '\n';
    queue<int> q;
    b_v[v] = true;
    cout << v << ' ';
    q.push(v);
    while(!q.empty()) {
        int cnt = q.front(); q.pop();
        for(int next : graph[cnt]) {
            if(!b_v[next]) {
                cout << next << ' ';
                b_v[next] = true;
                q.push(next);
            }
        }
    }
    cout << '\n';
    return 0;
}