#include <iostream>
#include <vector>
using namespace std;
bool visited[1001];
void dfs(vector<vector<int>> &graph, int cnt) {
    visited[cnt] = true;
    for(int next : graph[cnt]) {
        if(!visited[next]) dfs(graph, next);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1); 
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(graph, i);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}