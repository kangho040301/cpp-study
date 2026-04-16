#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int from, to, cost;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int n, m, w; cin >> n >> m >> w;
        vector<Edge> way(2*m + w);
        vector<int> time(n+1);
        bool yes = false;
        for(int i = 0; i < 2*m; i += 2) {
            int s, e, t; cin >> s >> e >> t;
            way[i].from = s;
            way[i].to = e;
            way[i].cost = t;
            way[i+1].from = e;
            way[i+1].to = s;
            way[i+1].cost = t;
        }
        for(int i = 2*m; i < 2*m + w; i++) {
            int s, e, t; cin >> s >> e >> t;
            way[i].from = s;
            way[i].to = e;
            way[i].cost = -t;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 2*m + w; j++) {
                int from = way[j].from;
                int to = way[j].to;
                int cost = way[j].cost;
            
                if(time[to] > time[from] + cost) {
                    time[to] = time[from] + cost;
                    
                    if(i == n) yes = true;
                }
            }
        }

        if(yes) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}