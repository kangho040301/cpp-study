#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int visited[100001];
int num = 1;
void dfs(vector<vector<int>> &graph, int r) {
    visited[r] = num++;
    for(int n : graph[r]) {
        if(!visited[n]) dfs(graph, n);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, r; cin >> n >> m >> r;
    int first = 0;
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
    dfs(graph, r);
    for(int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
    return 0;
}