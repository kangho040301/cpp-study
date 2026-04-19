#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int,int>>> adj;
bool visited[100001];
int max_diameter = 0;
int dfs(int cnt) {
    int first_max = 0;
    int second_max = 0;

    for(auto& next : adj[cnt]) {
        if(!visited[next.first]) {
            visited[next.first] = true;
            int len = dfs(next.first) + next.second;
            if(first_max < len) {
                second_max = first_max;
                first_max = len;
            }
            else if(second_max < len) {
                second_max = len;
            }
        }
    }

    max_diameter = max(max_diameter, first_max + second_max);

    return first_max;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    adj.resize(n+1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        while(true) {
            int t, d; cin >> t;
            if(t == -1) break;
            cin >> d;
            adj[x].push_back({t, d});
        }
    }

    visited[1] = true;
    dfs(1);
    cout << max_diameter << '\n';
    return 0;
}
