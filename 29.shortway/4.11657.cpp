#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<Edge> edge(m);
    vector<long long> time(n+1,1e8);
    time[1] = 0;
    for(int i = 0; i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if(time[u] != 1e8 && time[v] > time[u] + w) {
                time[v] = time[u] + w;

                if(i == n) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(time[i] >= 1e8) cout << -1 << '\n';
        else cout << time[i] << '\n';
    }
    return 0;
}
//벨만-포드 알고리즘