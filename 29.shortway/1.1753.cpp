#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int start; cin >> start;
    vector<int> dist(n+1,INT_MAX);
    dist[start] = 0;
    vector<vector<pair<int,int>>> vp(n+1); //first : 가는 곳, second : 가중치
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        vp[u].push_back({v,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; //first : 거리값, second : 위치 
    q.push({0, start});
    while(!q.empty()) {
        int d = q.top().first;
        int cnt = q.top().second;
        q.pop();

        if(dist[cnt] < d) continue;
        for(pair<int,int> next : vp[cnt]) {
            if(dist[next.first] > d + next.second) {
                dist[next.first] = d + next.second;
                q.push({dist[next.first], next.first});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}