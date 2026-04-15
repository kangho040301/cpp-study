#include <iostream>
#include <vector>
using namespace std;
int n, m, r;
vector<int> item(101);
vector<vector<pair<int,int>>> adj(101); //{위치, 거리}
vector<bool> visited(101);
vector<bool> got_item(101);
int ans = 0;
void dfs(int cnt, int len) {
    visited[cnt] = true;
    if(!got_item[cnt]) {
        got_item[cnt] = true;
        ans += item[cnt];
    }
    for(auto& next : adj[cnt]) {
        if(!visited[next.first] && len + next.second <= m) {
            dfs(next.first, len + next.second);
            visited[next.first] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for(int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        adj[a].push_back({b,l});
        adj[b].push_back({a,l});
    }
    int max_ans = 0;
    for(int i = 1; i <= n; i++) {
        dfs(i, 0);
        max_ans = max(max_ans, ans);
        fill(visited.begin(), visited.end(), false);
        fill(got_item.begin(), got_item.end(), false);
        ans = 0;
    }
    cout << max_ans << '\n';
    return 0;
}