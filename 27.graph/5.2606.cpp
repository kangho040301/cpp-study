#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    int r; cin >> r;
    
    vector<vector<int>> net(n+1);
    for(int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        net[u].push_back(v);
        net[v].push_back(u);
    }
    vector<bool> infected(n+1);
    queue<int> q;
    infected[1] = true;
    q.push(1);
    int ans = 0;
    while(!q.empty()) {
        int cnt = q.front(); q.pop();
        for(int next : net[cnt]) {
            if(!infected[next]) {
                infected[next] = true;
                ans++;
                q.push(next);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}