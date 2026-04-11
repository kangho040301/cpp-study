#include <iostream>
#include <vector>
using namespace std;
bool know[51];
bool visited[51];
void dfs(vector<vector<int>>& adj, int cnt) {
    visited[cnt] = true;
    for(int x : adj[cnt]) {
        if(!visited[x]) {
            know[x] = true;
            dfs(adj, x);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int k; cin >> k;
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        know[a] = true;
    }
    vector<vector<int>> member(m);
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            int x; cin >> x;
            member[i].push_back(x);
        }

        for(int a = 0; a < p; a++) {
            for(int b = a; b < p; b++) {
                adj[member[i][a]].push_back(member[i][b]);
                adj[member[i][b]].push_back(member[i][a]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(know[i]) dfs(adj, i);
    }
    int ans = m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < member[i].size(); j++) {
            if(know[member[i][j]]) {
                ans--;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
