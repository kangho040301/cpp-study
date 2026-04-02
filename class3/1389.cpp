#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int bfs(vector<vector<int>>& l, int n) {
    int size = l.size();
    vector<bool> visited(size);
    vector<int> step(size);
    visited[n] = true;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int cnt = q.front(); q.pop();
        for(int next : l[cnt]) {
            if(!visited[next]) {
                visited[next] = true;
                step[next] = step[cnt] + 1;
                q.push(next);
            }
        }
    }
    int sum = 0;
    for(int a : step) {
        sum += a;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> l(n+1);
    while(m--) {
        int u, v; cin >> u >> v;
        l[u].push_back(v);
        l[v].push_back(u);
    }
    int bmin = 1000000000;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int b = bfs(l,i);
        if(b < bmin) {
            bmin = b;
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}