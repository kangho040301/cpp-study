#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> last_rank(n+1);
        vector<int> degree(n+1);
        //adj[x][y] = true; x가 y보다 앞이다
        vector<vector<bool>> adj(n+1,vector<bool>(n+1));
        for(int i = 1; i <= n; i++) {
            cin >> last_rank[i];
            degree[last_rank[i]] = i - 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                adj[last_rank[i]][last_rank[j]] = true;
            }
        }

        int m; cin >> m;
        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            if(adj[u][v]) {
                adj[u][v] = false; adj[v][u] = true;
                degree[v]--; degree[u]++;
            }
            else if(adj[v][u]) {
                adj[v][u] = false; adj[u][v] = true;
                degree[u]--; degree[v]++;
            }
        }
        bool error = false;
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            if(q.size() > 1) {
                error = true;
                cout << "?\n";
                break;
            }
            int cnt = q.front(); q.pop();
            ans.push_back(cnt);

            for(int i = 1; i <= n; i++) {
                if(adj[cnt][i]) {
                    degree[i]--;
                    if(degree[i] == 0) q.push(i);
                }
            }
        }
        if(ans.size() < n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        if(error) continue;
        
        for(int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}