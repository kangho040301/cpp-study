#include <iostream>
#include <vector>
using namespace std;
int max_diameter = 0;
vector<vector<pair<int,int>>> adj;
int dfs(int cnt) {
    int first_max = 0;
    int second_max = 0;

    for(auto& next : adj[cnt]) {
        int len = dfs(next.first) + next.second;

        if(len > first_max) {
            second_max = first_max;
            first_max = len;
        }
        else if(len > second_max) {
            second_max = len;
        }
    }
    max_diameter = max(max_diameter, first_max + second_max);

    return first_max;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    adj.resize(n+1);
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dfs(1);

    cout << max_diameter << '\n';
    return 0;
}
