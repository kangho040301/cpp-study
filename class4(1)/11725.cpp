#include <iostream>
#include <vector>
using namespace std;
bool visited[100001];
void solve(vector<int>& p, vector<vector<int>>& c, int cnt) {
    for(int next : c[cnt]) {
        if(!visited[next]) {
            visited[next] = true;
            p[next] = cnt;
            solve(p, c, next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> parent(n+1);
    vector<vector<int>> connect(n+1);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    solve(parent, connect, 1);
    for(int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}